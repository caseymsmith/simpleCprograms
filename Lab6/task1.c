/*  
Write your own getenv() function called mygetenv() function which has same syntax and semantics
Write a simple C program to show your mygetenv() function works well
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *myfindenv(const char *name, int *offset);
char * mygetenv(const char *name);

int main()
{
 printf("HOME=%s\n", mygetenv("HOME"));
 printf("PATH=%s\n", mygetenv("PATH"));
 printf("ROOTPATH=%s\n", mygetenv("ROOTPATH"));
 return 0;
}


char * myfindenv(const char *name, int *offset){
	extern char **environ;
	int len, i;
	const char *nullPointer;
	char **p, *comboPointer;


	if (name == NULL || environ == NULL)
		return (NULL);
	for (nullPointer = name; *nullPointer && *nullPointer != '='; ++nullPointer)
		;
	len = nullPointer - name; //removes = in arg name
	for (p = environ; (comboPointer = *p) != NULL; ++p) {
		for (nullPointer = name, i = len; i && *comboPointer; i--)
			if (*comboPointer++ != *nullPointer++)
				break;
		if (i == 0 && *comboPointer++ == '=') {
			*offset = p - environ; //sets offset to be the offset of comboPointer
			return (comboPointer); //returns pointer to value associated with name
		}
	} 

	return (NULL); //if not the value with the associated name it returns NULL. 
}


char * mygetenv(const char *name){
	
	int offset;

	return (myfindenv(name, &offset));
} //retuns pointer to name value and if anything else it's NULL. 

