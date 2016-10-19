//Write a c code to copy a content of any readable file (foo) to a file(clone2) with open files using
//a buffer (created output file mode will be rwxrwx---).

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFFER_SIZE 4096

int main(){
    	int InFileDes,OutFileDes;
    	int nbyte;
    	char buffer[BUFFER_SIZE];

    	InFileDes=open("foo.txt", O_RDONLY); //open file for read only
    	OutFileDes = open ("clone2.txt", O_WRONLY|O_CREAT, 0770);
    	fchmod(OutFileDes, 0770);
    	while((nbyte=read(InFileDes, buffer, BUFFER_SIZE)) > 0)
    	if (write (OutFileDes, buffer, nbyte) != nbyte){
            	puts("Write Error.");
            	exit (1);
    	}
    	if (nbyte <0){
            	puts("Read Error.");
            	exit(1);
    	}

    	close(InFileDes);
    	close (OutFileDes);
    	exit(0);
}

