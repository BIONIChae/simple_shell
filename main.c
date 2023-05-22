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
char *inputComm = NULL, *arg[10] = {NULL}, *value;
int status, errnum = errno, counter = 0;
while (1)
{
write(STDOUT_FILENO, "Enter a command: ", strlen("Enter a command: "));
getline(&inputComm, &size, stdin);
if (inputComm[strlen(inputComm) - 1] == '\n')
inputComm[strlen(inputComm) - 1] = '\0';
if (strcmp(inputComm, "exit") == 0)
break;
else if (inputComm[0] == '\0')
continue;
value = strtok(inputComm, " ");
while (value != NULL)
{
arg[counter] = value;
counter++;
value = strtok(NULL, " ");
}
status = execv(arg[0], arg);
if (status != 0)
{
switch (errnum)
{
case ENOENT:
write(STDERR_FD, "404:Command not found\n", strlen("404:Command not found\n"));
break;
case EACCES:
write(STDERR_FD, "Permission denied\n", strlen("Permission denied\n"));
break;
default:
write(STDERR_FD, "Error detected\n", strlen("Error detected\n"));
break;
}
}
}
free(inputComm);
return (0);
}
