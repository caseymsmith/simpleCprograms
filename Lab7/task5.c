#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void loop();

int main(){
	int i, x;
	sigset_t set1;
	sigemptyset(&set1);
	sigaddset(&set1, SIGINT);
	sigaddset(&set1, SIGQUIT);
	sigset_t set2;
	sigemptyset(&set2);
	sigaddset(&set2, SIGQUIT);
	sigprocmask(SIG_BLOCK, &set1, NULL);
	loop();
	printf("\n");

	sigprocmask(SIG_UNBLOCK, &set2, NULL);
	loop();

	exit(0);
}

void loop(){
	int y;
	for(y=1; y < 6; y++){
		printf("Current: %d\n", y);
		sleep(1);
	}

}