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
char *inputComm = NULL, *arg[5] = {NULL}, *value;
int status, errnum = errno, counter = 0, i = 0;
while (write(STDOUT_FILENO, "Enter a command: ", strlen("Enter a command: "))
&& getline(&inputComm, &size, stdin) == -1)
{
if (inputComm[strlen(inputComm) - 1] == '\n')
inputComm[strlen(inputComm) - 1] = '\0';
if (strcmp(inputComm, "exit") == 0)
break;
else if (inputComm[0] == '\0')
continue;
counter = 0;
for (value = strtok(inputComm, " "); value != NULL && counter < 4;
value = strtok(NULL, " "))
{
arg[counter++] = strdup(value);
}
arg[counter] = NULL;
status = execvp(arg[0], arg);
if (status != 0)
{
switch (errnum)
{
case ENOENT:
perror("Command not found\n");
break;
case EACCES:
perror("Permission denied\n");
break;
default:
perror("Error executing command\n");
break;
}
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
