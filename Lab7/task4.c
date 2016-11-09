//Write a complete C program in which two children processes send
//signal to the parent. The forst child send message SIGUSR1 to the 
//parent and the parent process response by writing message "Hi Honey! 
//Anything wrong?". The second child send message SIGUSR2 to the parent and 
//the parent response by writing message "Do you make trouble again?".

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
int loop=1;

void message(int signum)
{
	if(signum == SIGUSR1){
		printf("Hi Honey! Anything wrong?\n");
	}	
	else if(signum == SIGUSR2) {
		printf("Do you make trouble again?\n");
	}

	loop=0;
}

int main(){

	pid_t pid, pid2; 
	int stat;

// pid=fork(); //child 1
// pid2=fork(); //child 2

// signal(SIGUSR1, message);
// signal(SIGUSR2, message);  

// if(pid == 0){ //child 1 sends signal
// 	if(pid2 == 0){ //child 2 sends signal
// 	kill(getppid(), SIGUSR1);
// 	sleep(1);
// 	kill(getppid(), SIGUSR2);	 
// 	}
// else{ //parent waits 
// 	pid2=wait(&stat);
// }
// }

pid = fork(); //creates child 1
if(pid!=0){  
	pid2=fork(); //creates child 2
	if(pid2!=0){ //parent process
		sleep(1);
		kill(pid, SIGUSR1); //ends the child
		kill(pid2, SIGUSR2);
		pid=wait(&stat);
		pid2=wait(&stat);
	}
	else{ //signal for the second child
		signal(SIGUSR2, message);
		while(loop); 
		//infinite loop to make sure it doesn't quit before it receives the signal
	}

}
else { //signal for the first child
signal(SIGUSR1, message);
while(loop);
//infinite loop to make sure it doesn't quit before it receives the signal
}

exit(0);
}

