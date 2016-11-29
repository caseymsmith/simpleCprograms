#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char command[25];   			 //holds the first argument and the concat of the two args
  char fname[25];   		 //holds the second argument
  char outString[100]; 
  FILE *fpointer;   			 //pointer for popen
 
 
  printf("Enter a shell command:\n");
  scanf ("%[^\n]%*c", command);
    
  printf("Enter the file name:\n");
  scanf ("%[^\n]%*c", fname);
   
  strcat(command, " ");
  strcat(command, fname);
 //concat the two arguments together

  fpointer = popen(command, "r");  //Send argument to the child with popen 
  //because r is the second parameter, the output comes from the parent

  while (fgets(outString, 100, fpointer) != NULL){
	printf("%s", outString);
  }

  pclose(fpointer);
  usleep(500); //sleep for half a second to let process finish
  
  return 0;
}