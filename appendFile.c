//Write a simple c code which open two files (foo, foo1)and append to a file (foo12) by using the
//lseek system call (created output file mode will be rwxrw---).

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int main(){
    	int inf, inf2, outf;
    	off_t offset;
    	char current;

    	inf=open("foo.txt", O_RDONLY);
    	inf2=open("foo1.txt", O_RDONLY);
    	outf=open("foo12.txt", O_WRONLY|O_CREAT, 0760);
    	fchmod(outf, 0760);

    	offset=lseek(outf, 0, SEEK_END);

    	while(read(inf, &current, 1)!=0){
            	write(outf, &current, 1);
            	offset--;
    	}

    	while(read(inf2, &current, 1) !=0){
            	write(outf, &current, 1);
    	offset--;
    	}

    	close(inf);
    	close(inf2);
    	close(outf);
    	exit(0);
}
