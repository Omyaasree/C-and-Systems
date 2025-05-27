// A hash function that maps strings to their hash values.
// Use the MPEG-2 CRC32 operation. As Paul about MPEG :)
// See https://stackoverflow.com/
//      questions/54339800/how-to-modify-crc-32-to-crc-32-mpeg-2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // to convert all to lower case and punctuation

#define table 256
//We will only have 256 entries.  So each entry stores a range of Hash Function values.

#define range ((0xFFFFFFFF / table) + 1)

typedef struct Node {
    char* strng;
    int count;
    struct Node* next;
} Node;

typedef struct Bucket {
    unsigned lowest; // lowest value of the Hash Function for this Table entry
    unsigned highest; // highest value of the Hash Function for this Table entry
    Node* list; // Linked List of strings whose Hash Function value is between lowest and highest
} Bucket;

Bucket hashTable[table];

// APPENDIX CODE

unsigned hash(const char* val) {
    unsigned hashVal = 0xffffffff;
    while (*val != 0) {
        hashVal ^= ((const unsigned) *val) << 24;
        for (int j = 0; j < 8; j++) { // each bit in this char
            unsigned msb = hashVal >> 31;
            hashVal <<= 1;
            hashVal ^= (0 - msb) & 0x04C11DB7;
        }
        val++; // each char in the string
    }
    return hashVal;
}


void initialize() {
    for (int i = 0; i < table; i++) { // going through all the buckets
        hashTable[i].lowest = i * range;

        if(i == table - 1){
        	hashTable[i].highest = 0xFFFFFFFF; // For the last bucket,  is set to the maximum possible value
        }else{
        	hashTable[i].highest = (i + 1) * range - 1;
        }

        hashTable[i].list = NULL; // This means the bucket starts empty.
    }
}


void add(const char* word) {

	char* lower = strdup(word);


    if (strlen(lower) == 0) {
        free(lower); // nothing to add
        return;
    }

    unsigned hashVal = hash(lower);

    int index = hashVal / range;  // Determine the bucket index

    Bucket* check = &hashTable[index];

    Node* current = hashTable[index].list;

    // Search for the word in the list
    while (current != NULL) {
        if (strcmp(current->strng, lower) == 0) {
            current->count++; // Word already exists, increment count
            free(lower); // freeing
            return;
        }
        current = current->next;
    }

    // Word not found, add a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->strng = lower;
    newNode->count = 1;
    newNode->next = check->list;
    check->list = newNode; // Insert at the head of the linked list
    // total ++;
}

// Find count of a word in the hash table
int find(const char* word) {
    unsigned h = hash(word); //Uses the  function to calculate the hash value
    int index = h / range; //Each bucket covers a specific range of hash values
    Node* current = hashTable[index].list; //current will be null,
    //Retrieves the linked list in the bucket where the word may be stored.

    while (current != NULL) {
        if (strcmp(current->strng, word) == 0) {
            return current->count; // If a match is found, the function returns the  value
        }
        current = current->next;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("missing file name in the arguments");
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");

    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    initialize();

    char word[256];

    while (fscanf(fp, "%255s", word) == 1) { // fscanf returns 1 after reading good values
    	//Reads a word from the file (up to 255 characters long) and stores it in the  buffer
        if (strlen(word) > 0) {
            add(word);
        }
    }

    fclose(fp); // close file

  // printTable();

    printf("Enter words to search for (Ctrl+D/Ctrl+Z to exit):\n");

    while(scanf("%s", word) != EOF){ // condition of ctrl c and ctrl z


        if (strlen(word) == 0) {
            printf("Invalid word. Please try again.\n");
            continue;
        }

        int count = find(word);
        printf("%d\n", count);

    }

    printf("\n BYE \n");
    return 0;
}

//void printTable() {
//    int totalWords = 0;
//
//    for (int i = 0; i < table; i++) {
//        Node* current = hashTable[i].list;
//        while (current) {
//            printf("%s: %d\n", current->strng, current->count);
//            totalWords += current->count;
//            current = current->next;
//        }
//    }
//
//    printf("\nTotal number of words: %d\n", totalWords);
//}


// for the search word

//        for (int i = 0; word[i]; i++) {
//            word[i] = tolower(word[i]); // to lower
//            if (ispunct(word[i])) { // to remove the punctuation
//                word[i] = '\0'; // marking the end of the word as a string
//                break;
//            }
//        }

//	if(total >= 256){
//		return;
//	}

//	if (!lower) return;
//
//	int valid = 1;
//
//	for (int i = 0; lower[i]; i++) {
//	    lower[i] = tolower((unsigned char)lower[i]);
//
//	    // If any character is not a letter, mark word as invalid
//	    if (!isalpha((unsigned char)lower[i])) {
//	        valid = 0;
//	        break;
//	    }
//	}
//
//	if (!valid || strlen(lower) == 0) {
//	    free(lower); // Don't add invalid words
//	    return;
//	}

	//THIS WORKS FOR WORDS LIKE let's

//    char* lower = strdup(word); //strdup makes a copy of the word
//    int i = 0;
//    while (lower[i]) {
//        lower[i] = tolower((unsigned char)lower[i]);
//
	//        if (!isalpha((unsigned char)lower[i])) {
//            lower[i] = '\0';
//            break;
//        }
//
//        i++;
//    }

//    for (int i = 0; lower[i]; i++) {
//        lower[i] = tolower(lower[i]); // converting the char is a lower
//        if (ispunct(lower[i])) { // ispunct checks if the charecter is a punct or not
//            lower[i] = '\0';  // Remove punctuation and determine the end of word
//            // assuming each word is a string adn 0 is the termination of a string
//            break;
//        }
//    }
