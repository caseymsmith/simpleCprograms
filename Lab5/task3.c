/*
Write your own function, myasctimem which operates exactly same as char *asctime(const struct
tm *timeptr). A C program will demonstrate the myasctime function.

Casey Smith 
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* myasctime (const struct tm *timeptr){

 static const char day[][10] = {
	"Sunday", "Monday", "Tuesday", "Wednesday", "Thusday", "Friday", "Saturday"
  };
  static const char month[][10] = {
	"January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"
  };
  static char output[26];
  sprintf(output, "%s %s %d %d:%d:%d %d",day[timeptr->tm_wday],month[timeptr->tm_mon],
	timeptr->tm_mday, timeptr->tm_hour,timeptr->tm_min, timeptr->tm_sec, 1900 + timeptr->tm_year);
  return output;
}


int main (){
	time_t currentTime;
	struct tm * timeStruct;


	time(&currentTime);
	timeStruct=localtime(&currentTime);


	printf("The current date & time is: %s\n", myasctime(timeStruct));
	exit(0);
}




