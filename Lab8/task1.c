#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *factorial(void *numberIn)
{
	
	int myInt=atoi(numberIn); //stores the value argument passed to this thread
	//takes the number from the command line and param & makes it an int
    int total=1; //holds the factorial
    for(int i=1; i<=myInt; i++){
    	total=total*i; 
    }
    printf("The factorial of the argument is: %i\n", total);
    return 0;
}
  

void *sum(void *numberIn)
{
	int myInt=atoi(numberIn);
	//takes the number from the command line and param & makes it an int
    int total=0; //holds the factorial
    for(int i=1; i<=myInt; i++){
    	total=total+i;
    }
    printf("The sum of the argument is: %i\n", total);
    return 0;
}
  

int main(int argc, char* argv[]){

    pthread_t tid; //integer used to identify the thread in the system
    printf("Before Thread\n");
    pthread_create(&tid, NULL, factorial, argv[1]); //function to create thread
    //arg1: porinter to thread_id set by this function 
    //arg3: name of function to be executed for the thread created
    //arg4: used to pass arguments to thread
    pthread_create(&tid, NULL, sum, argv[1]);
    pthread_join(tid, NULL); //similar to wait() process. blocks the calling 
    //thread until the thread with identifier equal to the first argument terminates
    printf("After Thread\n");
    exit(0);
}