//Modify alarm.c to use sigaction

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int alarm_fired=0; 
struct sigaction sigact; /* for sigaction call */

void ding (int sig){
	alarm_fired = 1; 
}

int main(){
	pid_t pid; 
	printf("alarm application starting\n");

	pid = fork();
	switch(pid){
		case -1:
		/*Failure*/
		perror("fork failed");
		exit(1);

		case 0: 
		/*Child*/
		sleep(5);
		kill(getppid(), SIGALRM);
		exit(0);
	}

	/* if we get here we are the parent process */
	printf("wait for the alarm to go off\n");
	//(void) signal(SIGALRM, ding);
	//replacing the signal from the alarm.c code to use sigaction 
	
	sigemptyset(&sigact.sa_mask); //clears sigaction structure
	sigact.sa_flags=0; //sets the flag to 0
	sigact.sa_handler=ding; //sets signal action handler to ding

	sigaction(SIGALRM, &sigact, NULL); 
	 /*change the action change for signal SIGALRM */

	pause();
	if(alarm_fired)
		printf("Ding!\n");

	printf("done\n");
	exit(0);
}