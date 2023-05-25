#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "unix.h"
#include <errno.h>
#define STDOUT_FD 1
#define STDERR_FD 2
#define SHELL_NAME "hsh"

/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
size_t size = 0;
char *inputComm = NULL, *arg[6] = {NULL}, *value;
int status, counter = 0, i = 0;
while (1)
{
/*write(STDOUT_FILENO, "Enter a command: ", strlen("Enter a command: "));*/
if (getline(&inputComm, &size, stdin) == -1)
{
perror("Error in getline");
free(inputComm);
inputComm = NULL;
break;
}
if (inputComm[strlen(inputComm) - 1] == '\n')
inputComm[strlen(inputComm) - 1] = '\0';
if (strcmp(inputComm, "exit") == 0)
break;
else if (inputComm[0] == '\0')
continue;
counter = 0;
for (value = strtok(inputComm, " "); value != NULL && counter < 4;
value = strtok(NULL, " "))
arg[counter++] = strdup(value);
arg[counter] = NULL;
if (counter == 5 && value != NULL)
perror("Too many arguments\n");
status = execvp(arg[0], arg);
if (status != 0)
{
perror("Error executing command\n");
break;
}
for (i = 0; i < counter; i++)
{
free(arg[i]);
arg[i] = NULL;
}
}
free(inputComm);
return (0);
}
