/*
Copy forkWait.c from previous task 3 to a file named forkEXec.c. Modify forkExec.c so the 
child process image is replaced by the image of a program named child. Use one of the exec
family of functions to do this. Write child.c to do the same thing as the child process did 
in Task4.
-The child should give its pid each time it prints the message
-The parent should give its pid each time it prints the message
-The child program should take three command-line arguments, the mesage, nc, and tc. 
-To get an interesting exit status from the child, have it return 37, rather than 0. 

Casey Smith 
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

  char * childMessage = "This is the child";
  char *const childParams[] = {argv[1], argv[3], childMessage};

  printf("fork program starting\n");
  pid = fork(); //fork is called, dividing the program into 2 separate processes
  switch(pid)
  {
  case -1:
    perror("fork failed");
    exit(1);

  case 0:  //process 1, child process
    //the child exectues a different program
  if (execv ("/Users/Casey/Documents/350/lab6/child", childParams) <0)
    {
    printf ("Exec function error.");
    exit (1);
    }

    break;
    
  default: //process 2, parent process.
    message= "This is the parent";
    for(; np > 0; np--){
    printf("%s", message);
    printf(" and the parent's pid is: %d\n", getpid());
     //printf("other parent pid=%d\n", getppid());
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
