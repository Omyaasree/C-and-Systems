/* socketdemo.c
 *
 * Listen for a socket connection,
 * or if an IP address is given on the command line,
 * connect to a remote socket.
 *
 * @author: phaskell
 * @copyright:  Paul Haskell. 2024.
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <ifaddrs.h>


// Constants and globals
const int PORT = 12345;


struct Server {
	// File Descriptors.
	int listenFd;
	int sockFds[128]; // all the socket fd's for the server
};

void init(struct Server* srv) {
	// Initialize array of fd's.
	for (int i = 0; i < 128; i++) {
		srv->sockFds[i] = -1;
	}

	// Ignore SIGPIPE, to avoid Server crashing if any remote end closes.
	signal(SIGPIPE, SIG_IGN);
}

// Get a free fd from the array.
int getIndex(struct Server* srv) {
	for (int i = 0; i < 128; i++) {
		if (srv->sockFds[i] < 0) { return i; }
	}
	return -1;
}

// Some interesting info to send to the clients.
const char* words[27] = {
	"University of San Francisco",
	"University of California, Berkeley",
	"Stanford University",
	"San Jose State University",
	"San Francisco State University",
	"University of California, San Francisco",
	"Cal State University, East Bay",
	"Golden Gate University",
	"Palo Alto University",
	"Evergreen Community College",
	"University of Silicon Valley", // formerly Cogswell College
	"Skyline College",
	"Foothill College",
	"Mission College",
	"De Anza College",
	"West Valley College",
	"City College of San Francisco",
	"Berkeley City College",
	"Merritt College",
	"Contra Costa College",
	"University of the Pacific",
	"Peralta Community College",
	"Saint Mary's College",
	"Santa Clara University",
	"College of San Mateo",
	"Cañada College",
	"San Jose City College" };

const char* nextWord() {
	static int indx = 0;
	const char* retval = words[indx++];
	if (indx >= 27) { indx = 0; }
	return retval;
}

void cleanup(struct Server* srv) {
	for (int i = 0; i < 128; i++) {
		if (srv->sockFds[i] > 0) {
			close(srv->sockFds[i]);
			srv->sockFds[i] *= -1;
		}
	}
	close(srv->listenFd);
	srv->listenFd *= -1;
}

	// Get (non-loopback) IP address for current server.
void myIpAddrs(char* word) {
	struct ifaddrs* ifAddrStruct = NULL;
	struct ifaddrs* ifa = NULL;
	void* tmpAddrPtr = NULL;
	word[0] = 0;

	getifaddrs(&ifAddrStruct);

	for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {
		if (ifa->ifa_addr->sa_family == AF_INET) { // IPv4
			tmpAddrPtr = &((struct sockaddr_in*) ifa->ifa_addr)->sin_addr;
			char addressBuffer[INET_ADDRSTRLEN];
			inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
			if (strcmp(ifa->ifa_name, "lo") != 0) { // don't print loopback
				/***
				std::cout << std::endl << ifa->ifa_name << " : "
					<< addressBuffer;
				***/
				strcpy(word, addressBuffer);
			}
		}
	}
	freeifaddrs(ifAddrStruct);
}

void doListen(struct Server* srv, const char* serverAddr) {
	srv->listenFd = socket(AF_INET, SOCK_STREAM, 0);
	if (srv->listenFd < 0) { perror("socket() fail"); exit(1); }

	// Bind
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(serverAddr);
	socklen_t len = sizeof(addr);
	int retval = bind(srv->listenFd,(struct sockaddr*) &addr, len);
	//
	// Retry, if socket is in TIME_WAIT state
	int failCount = 0;
	while (failCount++ < 100 && retval < 0) {
		printf("."); fflush(stdout);
		sleep(1);
		retval = bind(srv->listenFd, (struct sockaddr*) &addr, len);
	}
	if (retval < 0) { perror("bind() fail."); exit(1); }

	// Listen
	printf("\nListening\n");
	retval = listen(srv->listenFd, 100);
	if (retval < 0) { perror("listen() failed."); exit(1); }

	// Set listening socket to be nonblocking, for accept().
	if (fcntl(srv->listenFd, F_SETFL, O_NONBLOCK) < 0) {
		perror("fcntl()");
		exit(1);
	}
}

void doAccept(struct Server* srv) {
	// Accept
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	const int remoteFd = accept(srv->listenFd, (struct sockaddr*) &addr, &len);
	if (remoteFd > 0) {
		/**
		// Make the remote fd nonblocking.
		if (fcntl(remoteFd, F_SETFL, O_NONBLOCK) < 0) {
			perror("fcntl2()");
			exit(1);
		}
		**/
		srv->sockFds[getIndex(srv)] = remoteFd;
	} else if (errno != EAGAIN && errno != EWOULDBLOCK) {
		perror("accept()");
		exit(1);
	}
}

void doWrites(struct Server* srv) {
	const char* msg = nextWord();
	for (int i = 0; i < 128; i++) {
		if (srv->sockFds[i] > 0) {
			const int retval = write(srv->sockFds[i], msg, strlen(msg)+1);
			if (retval < 0) {
				close(srv->sockFds[i]);
				srv->sockFds[i] *= -1;
			}
		}
	}
}


int main(int argc, char** argv) {
	// Random number generator.
	srand(time(0));

	// Listen for client connections on a socket.
	struct Server myServ;
	init(&myServ);
	char address[128];
	myIpAddrs(address);
	printf("Address: %s\n", address);

	doListen(&myServ, address);
	while (1) {
		doAccept(&myServ);
		doWrites(&myServ);
		const int sleepTime = (rand() % 10) + 1;
		sleep(sleepTime);
	}

	// Clean up
	return 0;
}
