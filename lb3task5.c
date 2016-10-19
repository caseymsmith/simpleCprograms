//Write a simple c code which open a file (foo) as a input and write into a file by using the lseek
//system call (foorev)as a reverse order (created output file mode will be rwxrw---).

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int main(){
    	int in, out;
    	char current;
    	off_t offset;

    	in=open("foo.txt", O_RDONLY);
    	out=open("foorev", O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    	fchmod(out, 0760); //changes outfile mode. 
    	offset = lseek(in,0,SEEK_END); //positioning the openfile offset

    	read(in, &current, 1); //reads the infile. 

    	while(offset > 0){  
    	read(in, &current, 1); //reads from the infile
    	write(out, &current, 1); //writes to the outfile
    	printf("read character %c\n", current); //prints to the screen what’s happening
    	lseek(in, -2, SEEK_CUR);  //moves position
    	offset--;
    	}
    	write(out, "\n", 1); //just some formatting for outfile 
    	printf("\n");  //just some formatting for command line

    	close(in);
    	close(out);
    	exit (0);
}
