#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h> 

#define LINELEN (80)

char *mygets(char *buf, int len);

int main(int argc, char *argv[])
{
	// How to run this:
	// run in terminal: gcc main.c -o ex1
	//		    gcc loopcmp.c -o loopcmp
	// 		    ./ex1 lencmp OR ./ex1 lexcmp
	char* compareProgram;
	char str1[LINELEN + 1];
	char str2[LINELEN + 1];
	int status = 0;

	compareProgram = argv[1];  // compare program is passed through the command line in the terminal
	// in this way: ./ex1 lencmp or  ./ex1 lexcmp
	while (1)
	{
		// get two strings from user
		printf("Enter two strings: ");
		mygets(str1, LINELEN);
		mygets(str2, LINELEN);
		char otherProgram[LINELEN] = "./";

		strcat(otherProgram, compareProgram);
		// prepare arguments for the next program
		char* myArgs[] = { otherProgram,str1, str2, NULL };

		//printf("otherprog is %s, str is %s str2 is %s",otherProgram,str1,str2);
		int pid = fork();

		if (pid == -1)
			return -2;	// fork failed

		if (pid == 0)		//This is the child process, go and 		run the compare program
		{
			if (execvp(otherProgram, myArgs) == -1)
				return -2;	// exec failed
		}
		else
		{

			wait(&status);

			printf("child process code is: %d\n", WEXITSTATUS(status));


		}

	}
	return 0;
}


char *mygets(char *buf, int len)
{
	char *retval;

	retval = fgets(buf, len, stdin);
	if (retval == NULL)
		exit(1);

	buf[len] = '\0';
	if (buf[strlen(buf) - 1] == 10) /* trim \r */
		buf[strlen(buf) - 1] = '\0';
	else if (retval) while (getchar() != '\n'); /* get to eol */

	return retval;
}

