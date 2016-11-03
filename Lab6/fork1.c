/*
fork1.c From BLP 4th edition, page 474 (page 457 in BLP 3rd edition)
Run the program to see what it does. 
Modify to take 4 command line arguments: 
1. nc - number of iterations for child process
2. np - number of iterations for parent process
3. tc - sleep time for child process
4. tp - sleep time for parent process
Then modify the code accordingly 
-Run the program as fork1 5 3 1 1. 
You should get the same result as running the original version. 

Casey Smith
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[]){
  pid_t pid;
  char *message;
  
  int nc = atoi(argv[1]); //# of iterations for child process
  int np = atoi(argv[2]); //# of iterations for parent process
  int tc = atoi(argv[3]); //sleep time for child process
  int tp = atoi(argv[4]); //sleep time for parent process
 
  printf("fork program starting\n");
  pid = fork();
  switch(pid)
  {
	case -1:
  	perror("fork failed");
  	exit(1);

	case 0:  //process 1
  	message= "This is the child";
  	for(; nc > 0; nc--){
    puts(message);
    sleep(tc);
    }
  	break;
    
	default: //process 2
  	message= "This is the parent";
  	for(; np > 0; np--){
    puts(message);
    sleep(tp);
    }
  	break;
  }
  
  exit(0);
 
}
