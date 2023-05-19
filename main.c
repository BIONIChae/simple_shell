#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "unix.h"
#include <errno.h>
#define SHELL_NAME "hsh"

/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
char **envp = environ, *cmd = NULL;
size_t size = 0;
char *a[] = {NULL, NULL};
int status, errnum;;
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
a[0] = cmd;
status = execve(cmd, a, envp);
errnum = errno;
if (status != 0)
{
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
