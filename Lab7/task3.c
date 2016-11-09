#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){

  pid_t pid; 
  int outFile;
  int stat;
  char c1[50]="Hi, Mom";
  char c2[50];

  umask(0);
  outFile = open("foo", O_RDWR | O_CREAT, 0644);

  pid=fork();
  pid2=fork();
  switch(pid)
  {
    case -1:
    perror("fork failed");
    exit(1);

    case 0:  //process 1, child process 
    write(outFile, c1, 50); //writes childs message to outFile(foo)
    break;

    default: //process 2, parent process 
    pid=wait(&stat); //makes sure the child terminates first 
    lseek(outFile, 0, SEEK_SET);
    //makes parent wait until childs process is done if parent process begins
    read(outFile, c2, 50); //reads outFile(foo) into character array c2
    printf("My son said %s\n", c2); //prints out array c2
    break;
}

close(outFile);
exit(0);

}