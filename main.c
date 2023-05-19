#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "unix.h"
#include <errno.h>
#define SHELL_NAME "hsh"

/**
* main - Entry point
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
* @envp: Array of environment variables
*
* Return: Always 0
*/
int main(int argc, char **argv, char **envp)
{
char *cmd = NULL;
size_t size = 0;

while (1)
{
write(STDOUT_FILENO, "Enter a command: ", strlen("Enter a command: "));
getline(&cmd, &size, stdin);

if (cmd[strlen(cmd) - 1] == '\n')
cmd[strlen(cmd) - 1] = '\0';

if (strcmp(cmd, "exit") == 0)
break;
else if (cmd[0] == '\0')
continue;
int status = execve(cmd, NULL, envp);
if (status != 0)
{
int errnum = errno;
switch (errnum)
{
case ENOENT:
write(2, "Error: command not found\n", strlen("Error: command not found\n"));
break;
case EACCES:
write(2, "Permission denied\n", strlen("Permission denied\n"));
break;
case ENOMEM:
write(2, "Insufficient memory\n", strlen("Insufficient memory\n"));
break;
default:
write(2, "Unknown error detected\n", strlen("Unknown error detected\n"));
break;
}
}
}
free(cmd);
return (0);
}
