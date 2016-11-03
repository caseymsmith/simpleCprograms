/*
Copy the modified fork1.c to file named forkWait.c
Modify forkWait.c so the parent process waits for the child to finish. 
Use the code from BLP 4th edition in page 475 (page 458 in 3rd edition), 
for the wait portion. Run forkWait with nc=5, np=3, tc=1 and tp=1. 

Results differ from the original problem in Task 2 (previous fork1.c)
Program now waits for child to finish. Previous task 2 child messages
appear with output because the program doesn't wait. 

*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pid_t wait(int *stat_loc);
//causes parent process to pause until one of its child processes is stopped.
//call returns the PID of the child process.

int main(int argc, char * argv[]){
  pid_t pid;
  char *message;
  
  int nc = atoi(argv[1]); //# of iterations for child process
  int np = atoi(argv[2]); //# of iterations for parent process
  int tc = atoi(argv[3]); //sleep time for child process
  int tp = atoi(argv[4]); //sleep time for parent process


  int exit_code; 
 
  printf("fork program starting\n");
  pid = fork(); //fork is called, dividing the program into 2 separate processes
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

    exit_code = 37;  

  	break;
    
	default: //process 2, parent process.
  	message= "This is the parent";
  	for(; np > 0; np--){
    puts(message);
    sleep(tp);
    }

    exit_code = 0;

  	break;
  }
 
 //this section of the program waits for the child process to finish
  if(pid != 0){
    int stat_val; 
    pid_t child_pid;

    child_pid = wait(&stat_val);

    printf("Child has finished: PID = %d\n", child_pid);
    if(WIFEXITED(stat_val))
      printf("Child Exited with code %d\n", WEXITSTATUS(stat_val));
    else
      printf("Child terminated abnormally\n");
  }
  
  exit(exit_code);
 
}


// E: Briefly describe how your result differs from the original program in Task 2. Explain.
// Program now waits for child to finish. Previous task 2 child messages appear with
// output because program doesn't wait for it to finish. 
