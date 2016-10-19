//Write a c code to copy a content of any readable file (foo) to a file (clone1) with open files but
//without using a buffer (created output file mode will be rw-rw-rw).

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
    	int InFileDes, OutFileDes;
    	char Ach;

    	/* open file for read only */
    	InFileDes = open("foo.txt", O_RDONLY);
    	/* open file for write only or create only, created file mode will rw_ _ _ _ _ _ _*/

    	OutFileDes = open ("clone1.txt", O_WRONLY|O_CREAT, 0666);
    	fchmod(OutFileDes, 0666); //changes mode
    	while(read(InFileDes, &Ach, 1) == 1)
    	write(OutFileDes, &Ach, 1);
    	close (InFileDes);
    	close (OutFileDes);
    	exit(0);
}
