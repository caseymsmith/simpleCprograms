/* 
Open utmp file, write a function named openUtmpFile that opens the utmp file and returns its file
descriptor. If the file can't be opened, the function writes an error message and exits
(thereby terminating the program). Call openUtmpFile in the main function. Compile  
program to check for errors. Read records from the utmp file, add code in the main function to 
loop through the utmp file, reading each record. For each record, just print the user name.
Add code in the loop to count the number of records that are USER_PROCESS records
(logged-in users). When the loop is done, print the number of logged-in users found.

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
#include <utmp.h>
#include <stddef.h>


int main(){
	openUtmpFile();


	exit(0);
}




int openUtmpFile(){
	int inFile; //for file descriptor
	int count=0; //counter for the number of users logged-in
	struct utmp file;




	if((inFile=open("/var/run/utmp", O_RDONLY)) == -1){
    	printf("There was an error opening the file!");
    exit(1);
	}    //conditional statement to make sure the utmp file can be opened




	while (read(inFile, & file, sizeof(struct utmp)) > 0){
    	printf("User name: %s\n", file.ut_user);


    	if (file.ut_type == 7){ //USER_PROCESS records are 7.
        	count++;
    	} //conditional statement to increment the counter based on array with user_process
	}


	printf("Number of logged-in users found: %d\n", count);


	close(inFile);
	return inFile;
}