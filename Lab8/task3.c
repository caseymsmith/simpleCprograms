#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 256
void err_sys(char *);
int main()
{
	int n, fd[2], size, int1, int2;
	pid_t pid;
	char sline[MAXLINE], rline[MAXLINE];

	if (pipe(fd) < 0) /* create a pipe*/
		err_sys("Pipe error");
	if ( (pid = fork()) < 0) /*create a child*/
		err_sys("Fork error");
	else if (pid > 0) /*parent use the pipe to send message to child*/
	{
 		close(fd[0]); /* fd[1] is used for sending data*/
		printf("Enter two integers:\n");
		
		while ( (size = read(STDIN_FILENO, sline, MAXLINE)) > 0)
		{
 			write(fd[1], sline, size); /*write to a pipe */
			sleep(1);
			printf("Enter two integers:\n");
		}
	}
	else /* child use pipe to receive message from the parent */
	{
		close(fd[1]);
		printf("The solution of your two integers is:");
 	
 		while ((n = read(fd[0], rline, MAXLINE))>0) /*read from the pipe */
		{
 		/* chose first two string as two integer */
		if (sscanf(rline, "%d%d", &int1, &int2) == 2){
			sprintf(rline, "The solution of your two integers is: %d\n", int1 + int2);
			n = strlen(rline);
			
			if (write(STDOUT_FILENO, rline, n) != n)
				err_sys("Write error");
		}
 		else /* if first two string is not integer */
			{
			if (write(STDOUT_FILENO, "Invalid arguments! \n", 19) != 19)
			err_sys("Write error");
			}
		}
	}
	return 0;
}
void err_sys(char *str)
{
	printf ("%s \n",str);
	exit (1);
}
