// dev: Charles DeGrapharee Exum
// contact: charlesexumdev@gmail.com
// date: 2018.05.31
#include "mallocconceptproof.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datastructure * makedatastructure(const char *s) { 
	//allocate memory for struct
	struct datastructure * ptr; // declare
	ptr = malloc(sizeof(struct datastructure)); // allocate memory size of struct datastructure
	if (ptr == 0) { // handle null reference
		puts("null reference");
		}
	
	// allocate memory for struct member
	ptr->length = strlen(s); // dynamically determine size
	ptr->data = malloc(ptr->length); // allocate memory for struct member
	if (ptr->data == 0) { // handle null reference
		free(ptr); // error -- free up memory for the struct
		puts("null reference"); 
		}
	strncpy(ptr->data, s, ptr->length); // store data in struct
	return ptr;
}

void destroydatastructure(struct datastructure * ptr) {
	free(ptr->data); // free struct member
	free(ptr); // free struct
	}

int main(int argc, char *argv[]) {
	struct datastructure *temp; // declare
	temp = makedatastructure("string literal"); // assign
	puts(temp->data); // proof
	destroydatastructure(temp); // clean up
	return 0;
	}
