/* server.c
 *
 * Listen for client socket connections,
 * accept them, write messages.
 *
 * @author: phaskell
 * @copyright: Paul Haskell. 2024.
 */


////
//// Include files
////
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <ifaddrs.h>


////
//// Constants and globals
////
const int PORT = 12345;


////
//// Methods
////
int doListen(const char* serverAddr) {
	// Create socket
	const int listenFd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenFd < 0) { perror("socket() fail"); exit(1); }

	// Bind socket to this server's address
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(serverAddr);
	socklen_t len = sizeof(addr);
	printf("s_addr is %u\n", addr.sin_addr.s_addr);

	// Bind address to listenFd.
	int retval = bind(listenFd,(struct sockaddr*) &addr, len);
	if (retval < 0) {
		printf("bind() fail with errno %d\n", errno);
		perror("bind() fail.");
		exit(1);
	}

	// Listen for a client, i.e. ready to accept.
	printf("\nListening\n");
	retval = listen(listenFd, 100);
	if (retval < 0) { perror("listen() failed."); exit(1); }

	// Return the listener socket fd.
	return listenFd;
}


int doAccept(int listenFd) {
	struct sockaddr_in addr;
	socklen_t len = sizeof(struct sockaddr_in);

	// Accept connection to client. Can accept multiple connections.
	const int remoteFd = accept(listenFd, (struct sockaddr*) &addr, &len);
	if (remoteFd < 0) { perror("accept() fail"); exit(1); }

	return remoteFd;
}


void doClose(int fd) {
	close(fd);
}


void doRead(int fd) {
	// Read message from remote server
	char buf[4096];
	int retval = read(fd, buf, 4096);
	if (retval <= 0) {
		doClose(fd);
		return;
	}
	buf[retval] = 0;
	printf("Read %s\n", buf);
}


////
//// Main module
////
int main(int argc, char** argv) {
	if (argc < 2) {
		printf("usage: server IP_ADDRESS_OF_SERVER\n");
		exit(0);
	}

	// Set up listening socket.
	const int listenFd = doListen(argv[1]);

	// Accept a remote connection, read it, and close down.
	const int acceptFd = doAccept(listenFd);
	doRead(acceptFd);
	doClose(acceptFd);
	doClose(listenFd);

	// Clean up
	return 0;
}
