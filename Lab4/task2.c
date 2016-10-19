/*
C program that receive sequence of integers on the command line 
and prints their sum to the screen. Using your own function to convert 
string to integer instead of using atoi function. Program exits with an 
appropriate error message under the following error condition: 
There is not at least one integer on the command line. 
*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int convStrToInt(char * str){
	int toInt=0;
	for(int x=0; x < strlen(str); x++){
		toInt=(toInt*10) + (str[x]-'0');
		printf("%d\n", toInt);
	}
	return toInt;
} //string to integer function

int main(int argc, char *argv[])
{

	int sum = 0;
	int curr;

	if (argc < 2)
	{
		printf("There are no arguments\n");
		exit (0);
	}

	for (int i = 1; i < argc; i++)
	{
		curr = convStrToInt(argv[i]);
		sum = sum + curr;
	}
	
	printf("Sum of the arguments: %d\n", sum);
	exit(0);
}


