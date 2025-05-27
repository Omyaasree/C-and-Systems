// filename: uniondemo.c
//
// Show a simple C union
//
// @author: phaskell

#include <stdio.h>


struct PacketType{ // unnamed struct
	short idValue;
	short controlFlags;
	short counter;
	short errCheck;
	unsigned char payload[160];
};


union DataPkt {
	struct PacketType header;
	unsigned char raw[176];
};


int main() {
	union DataPkt myPkt;

	myPkt.header.idValue = 0x40;
	myPkt.header.controlFlags = 0x51;
	myPkt.header.counter = 0x62;
	myPkt.header.errCheck = 0x73;

	myPkt.raw[0] = 0;
	myPkt.raw[1] = 1;
	/*
	myPkt.raw[2] = 2;
	myPkt.raw[3] = 3;
	myPkt.raw[4] = 4;
	myPkt.raw[5] = 5;
	*/
	myPkt.raw[6] = 6;
	myPkt.raw[7] = 7;
	myPkt.raw[8] = 8;
	myPkt.raw[9] = 9;

	printf("Size is %ld\n", sizeof(union DataPkt));
	printf("%04hx %04hx %04hx %04hx %02hx %02hx\n",
		myPkt.header.idValue, myPkt.header.controlFlags,
		myPkt.header.counter, myPkt.header.errCheck,
		myPkt.header.payload[0], myPkt.header.payload[1]);

	return 0;
}
