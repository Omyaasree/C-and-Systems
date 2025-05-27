/*
 * simple.c
 * this code left shift the short value 1 until the value remains the same
 * and right shift the char value until the value remains the same
 *  Created on: Mar 19, 2025
 *      Author: Omyaasree
 */

#include <stdio.h>

int main(){
	short var1 = 1;
	short var2 = 0; // another variable to store the last stored value and comparison

	while(var2 != var1){
		var2 = var1;
		var1 = var1 << 1; // left shifting the short
		printf("%hd\n", var2); // printing the short values
	}
	//printf("The final short value is %d", var2);

	char char1 = -128;
	char char2 = 0;

	while(char2 != char1){
		char2 = char1;
		char1 = char1 >> 1; // right shifting the char
		printf("%d \n", char2); // printing the double value of the chars
	}
	//printf("The final char value is %d", char2);

}

