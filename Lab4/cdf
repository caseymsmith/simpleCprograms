#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 2000

int main(int argc, char * argv[]){
    	int InFileDes,OutFileDes;
        int nbyte, check;
    	char buffer[BUFFER_SIZE];

        check=access(argv[1], R_OK && F_OK); 
        //F_OK tests existence. R_OK tests for readable-ness
        
        if(check == 0)
        {
    	InFileDes=open(argv[1], O_RDONLY); //open file for read only
    	OutFileDes = open (argv[2], O_WRONLY|O_CREAT, 0660);
    	umask(0); //allow changing permissions

    	while((nbyte=read(InFileDes, buffer, BUFFER_SIZE)) > 0){
    	write (OutFileDes, buffer, nbyte);
        }
        }
        else 
            printf("The input file is not readable\n");

    	close(InFileDes);
    	close (OutFileDes);
    	exit(0);
}
