/*
-Write a C program such that receive a text file name as a argument and open the file for
read. And then create a child process. Two processes are sharing same files for read.
Both the parent and the child read a byte at a time from the same file and write to
independent files. The parent process collect number characters and child collect nonnumber
characters. Without any form of synchronization, the output files for each
process will be intermixed between child and parent’s works.
-Modify the previous program and try to synchronize and get correct outputs for each
process.

Casey Smith 
*/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(int argc, char * argv[]){

  pid_t pid; 
  int inFile, outFile1, outFile2; //input file
  int stat;
  char c1, c2; //byte by byte

  umask(0);
  inFile = open(argv[1], O_RDONLY);
  outFile1 = open("wordsFile", O_WRONLY | O_CREAT, 0644);
  outFile2 = open("numberFile", O_WRONLY | O_CREAT, 0644);

//  printf("fork program starting\n");
  pid=fork();

  switch(pid)
  {
    case -1:
    perror("fork failed");
    exit(1);

  case 0:  //process 1, child process for words

  while (read(inFile, &c1, 1) != 0) {
    if(isdigit(c1) == 0)
          //everything that's not a white space/symbols and if it's not a digit
     write(outFile1, &c1, 1);
}
break;


  default: //process 2, parent process for numbers
  pid=wait(&stat);
  lseek(inFile, 0, SEEK_SET);
  //makes parent wait until childs process is done if parent process begins

  while (read(inFile, &c2, 1) != 0) {

    if(isdigit(c2) != 0) //condition collects words and spaces
      write(outFile2, &c2, 1);

  }
  break;

}

close(inFile);
close(outFile1);
close(outFile2);
exit(0);

}


// #include <sys/types.h>
// #include <sys/wait.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <fcntl.h>
// #include <sys/stat.h>

// int main(int argc, char * argv[]){

//   pid_t pid; 
//   int inFile, outFile1, outFile2; //input file
//   char c1, c2; //byte by byte
//   int i = 0;
//   int j = 0;   //used for while loops
//   int offset1, offset2;
//   umask(0);
//   inFile = open(argv[1], O_RDONLY);
//   outFile1 = open("wordsFile", O_WRONLY | O_CREAT, 0644);
//   outFile2 = open("numberFile", O_WRONLY | O_CREAT, 0644);

//   //get the size of the file
//   struct stat st;
//   stat(argv[1], &st);
//   int size = st.st_size;

//   //set both offsets to the start of the file
//   offset1 = lseek(inFile, 0, SEEK_SET);
//   offset2 = lseek(inFile, 0, SEEK_SET);

//   pid=fork();

//   switch(pid)
//   {
//     case -1:
//     perror("fork failed");
//     exit(1);

//   case 0:  //process 1, child process for words
  
//   //loop through using the size of the file
//   for (i=0; i <= size; i++) {
//     //use lseek to set the position to what offset1 is
//     lseek(inFile, offset1, SEEK_SET);
//     read(inFile, &c1, 1);

//     if((isgraph(c1) != 0) && (isdigit(c1) == 0)){
//           //everything that's not a white space/symbols and if it's not a digit
//      write(outFile1, &c1, 1);
//    }
//    printf("child \n");
//    offset1++;
//  }
//  break;

  
//   default: //process 2, parent process for numbers

//   for (j=0; j <= size; j++) {
//     //use lseek to set the position to what offset2 is
//     lseek(inFile, offset2, SEEK_SET);
//     read(inFile, &c2, 1);


//     if(isdigit(c2) != 0){
//       write(outFile2, &c2, 1);
//     }
//     printf("parent \n");
//     offset2++;
//   }
//   break;
// }

// close(inFile);
// close(outFile1);
// close(outFile2);
// exit(0);

// }
