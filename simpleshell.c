#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

/**
 * main - 
 *
 * Return: Always 0.
 */
int main(int ac, char **argv)
{
	char *buffer = NULL;
	size_t lenofbuffer = 0;
	int k, i;
	char **myprocesses;
	char *separator = " ";
	char *split;
	size_t mypid;
	int index = 0;
	int status;
	
	(void)ac;
	i = 0;
	while(*argv != NULL)
	{
		printf("#cisfun$");
		getline(&buffer, &lenofbuffer, stdin);
		myprocesses = malloc(lenofbuffer * sizeof(char));
		split = strtok(buffer, separator);
		while (split != NULL)
		{
			myprocesses[index] = split;
			index++;
			split = strtok(NULL, separator);
		}
		myprocesses[index] = NULL;
		while (myprocesses[i] != NULL)
		{
			printf("%s\n", myprocesses[i]);
			i++;
		}
		mypid = fork();
		if (mypid == 0)
		{
			k = execve(myprocesses[0],myprocesses,NULL);
			if (k == 0)
			{
				dprintf(2,"Error:");
			}
		}
		else
		{
			wait(&status);
			printf("Execution complete");
		}
	}
	return (0);
}
