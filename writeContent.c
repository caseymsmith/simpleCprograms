//Write a c code to copy a content of any readable 
//file (foo) to a file (clone) without open input
//file (use standard input and output).

#include <stdio.h>
#include <stdlib.h>

void main() {
    	FILE *f1, *f2;
    	char x;

    	f1=fopen("foo.txt", "r"); //opening the file in read mode

    	if (f1 == NULL){ //checking if opening the file is successful
    	puts ("This file can not be opened.");
    	exit (1);
    	}

    	f2=fopen("clone.txt", "w"); //opening the file in write mode

    	if (f2 == NULL) { //checking if opening the file is successful
    	puts("Unable to open this file");
    	fclose(f1);
    	exit(1);
    	}

    	do {
    	x = fgetc(f1); //reading the file char by char & writing on the new file, char by char.
    	fputc(x, f2);
    	} while (x != EOF);

    	fcloseall();
}
