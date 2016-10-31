/* Write your own mv called MyMv by using system calls link() and unlink(). Program
named MyMv can move a file from a current directory to a directory. Program receives
two arguments: file name and path to a directory where the file need to move.

Casey Smith 
 */

#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <libgen.h>
#include <limits.h>

// Casey Smith
// COSC 350

// arg[1] taking in file name move1.txt
// arg[1] current dir is in /Users/Casey/Documents/350/lab5
// arg[2] directory with path /Users/Casey/Documents/350

int main(int argc, char * argv[]){
	
struct stat sb; //declaring stat structure type
char * current; //holds cwd
char buff[PATH_MAX+1]; //buffer for cwd
char * path1=basename(argv[1]); 	//the basename of the first argument

//get file info & Save it in stat struct type
//S_ISDIR determines if file is acually a directory
if (stat(argv[2], &sb) == 0 && S_ISDIR(sb.st_mode))
{ 
    printf("\nSecond argument is a directory.\n"); 

    char * argument1 = argv[1];
    char * fileName; 

    if(argument1[0] != '/') //checks if it's a local file without a path
    {
    	strcat(argv[2], "/"); 
    	strcat(argv[2], argv[1]);
    }
    else //if it's a file path, gets the file name from it
    {
    	strcat(argv[2], "/");
    	fileName=basename(argv[1]);
    	strcat(argv[2], fileName);
    }

    link(argv[1], argv[2]);
    unlink(argv[1]);

	// current=getcwd(buff, PATH_MAX+1); //get cwd

	// char * slash = strcat(current, "/");	// add slash to path
	// char * condition1=strcat(slash, path1); 	//concatonate path with slash to file name
	// printf("\nFirst link argument path:%s\n", condition1);

	// char * slash2 = strcat(argv[2], "/");	// add slash to read in path
	// char * condition2=strcat(slash2, path1); 	//concatonate path with slash to file name
	// printf("Second link argument path:%s\n\n", condition2);

	// link(condition1, condition2);
	// unlink(condition1);





    //move a file to the directory
}
else{//second argument not a directory.
	printf("\nThe second argument was not a directory.\n");
	// umask(0);
	// mkdir(argv[2], 0777);	//creates new directory based on second argument

	// current=getcwd(buff, PATH_MAX+1); //gets cwd

	// char * slash = strcat(current, "/");	// add slash to path
	// char * condition1=strcat(slash, path1); 	//concatonate path with slash to file name
	// printf("\nFirst link argument path:%s\n", condition1);

	// char * slash2 = strcat(argv[2], "/");	// add slash to read in path
	// char * condition2=strcat(slash2, path1); 	//concatonate path with slash to file name
	// printf("Second link argument path:%s\n\n", condition2);

	// link(condition1, condition2);
	// unlink(condition1);

	link(argv[1], argv[2]);
	unlink(argv[1]);

}

}