/*
C porgram for sequence of the following:
-home directory going to Dir1 & Dir2, Dir2 going to Dir12
-using system calls, copy hello file under ~/Dir2/Dir12
-using system calls, make a symbolic link named toDir12 to directory Dir12
using system calls, make a symbolic link named toHello to executable
file ~/Dir12/hello
*/

#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char * argv[]){

	
	//creates Dir1, Dir2, and Dir12 directories
	umask(0);
	mkdir("/Users/Casey/Documents/350/lab4/Dir1", 777);
	mkdir("/Users/Casey/Documents/350/lab4/Dir2", 777);
	mkdir("/Users/Casey/Documents/350/lab4/Dir2/Dir12", 777);


	//copies hello file to ~/Dir2/Dir12
	system("cp ~/Documents/350/lab4/hello /Users/Casey/Documents/350/lab4/Dir2/Dir12");

	//symbolic link called toDir12 to Dir12
	symlink("/Users/Casey/Documents/350/lab4/Dir2/Dir12", "/Users/Casey/Documents/350/lab4/Dir1/toDir12");

	//symbolic link called toHello to executable file ~/Dir12/hello
	symlink("/Users/Casey/Documents/350/lab4/Dir2/Dir12/hello", "/Users/Casey/Documents/350/lab4/Dir1/toHello");

   char command[50];
      char command1[50];

   strcpy(command1, "ls" );
   system(command1);

   // strcpy(command, "./toHello" );
   // system(command);

   mkdir("/Users/Casey/Documents/350/lab4/Dir1/toDir12/newDir", 777);

	exit(0);
}
