#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// i dont know what i did 
// doesnt compile bruh

using namespace std;

// method to lower the uppercases
void lower(char* word, int length) {
	//printf("check1 \n");
	for(int j = 0 ; j < length ; j++){
		char val = word[j];
		if(65 <= val && val <= 90){ // the uppercase range is only from 65 to 90 
			val = val + 'a' - 'A'; // changing the uppercase to lowercase
		}
		printf("%c" , val); //print all the things same except changes uppercase to lowercase 
	}
};

struct Node {
    string word;
    Node* next;
};


class Node {
public:
    string word;
    Node* next;

    // Constructor
    Node(string w) {
        word = w;
        next = nullptr;
    }
};


class List {
	Node* head;
	List(){
		Node* next;
	}
    void addWord(string word) {
        Node* newNode = new Node(word);

        newNode->next = head;
        head = newNode;
    }

     ~List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

}

int main(){
	char words[10000] = "";

	while(1){

		cin >> words;
		int length = strlen(words);
		cout << length << endl;
		lower(words, length);
		printf(" ");
		cout << words << endl;

	}
};