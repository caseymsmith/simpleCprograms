/*
C function that takes one command-line argument, the name of an input file. 
The input file contains exactly one integer spread over a single line of up
to 80 characters. For example, the integer 3579 is embedded in the line 
az3mqrm5t?7!z*&gqmzt9v. Program uses system calls to do the following: 
a. open & read the input file, accumulating the discovered digit characters
into a character array (string)
b. convert the string to an integer (without using atoi function)
c. add 10 to the integer
d. convert the sum back to a string (using function convIntToStr) 
e. make a system call to write the string to standard output.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h> 
#include <string.h>

#define BUFFER_SIZE 1000

int main(int argc, char *argv[]){
	int inFile; //input file
	char arr[BUFFER_SIZE]; //holds input of file
	char out[80]; //holds string integer 
	int toInt;

	inFile = open(argv[1], O_RDONLY);
	read(inFile, arr, BUFFER_SIZE);

	for (int i=0; i <= strlen(arr); i++){
		if(isdigit(arr[i])){
			sprintf(out, "%s%c", out, arr[i]);
		}
	} //put things into array

	for(int x=0; x < strlen(out); x++){
		toInt=(toInt * 10) + (out[x] - '0');
	} //string to integer

	toInt=toInt+10; 
	//adding 10 to the integer


	printf("Initial: %s\n",out);
	convIntToStr(out, toInt); //converting the sum back to a string
	//printf("String: %s\n", out); //s must mean it's a string
	printf("Final: %d\n", toInt); //d means it's a numerical value
}


int convIntToStr(char * str, int x){
	sprintf(str, "%d", x);
	return (strlen(str));
} 
/* Convert int to string
Params: x is the int to be converted, 
str is the string into which to write. 
Returns length of the string */
