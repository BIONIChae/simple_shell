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
* Return: Always 0
*/
int main(void)
{
char *cmd = NULL;
char *const args[] = {cmd, NULL};
int status = execve(cmd,
size_t size = 0;
int status;
while (1)
{
write(STDOUT_FD, "Enter a command: ", strlen("Enter a command: "));
if (getline(&cmd, &size, stdin) == -1)
{
perror("getline");
exit(EXIT_FAILURE);
}
if (cmd[strlen(cmd) - 1] == '\n')
cmd[strlen(cmd) - 1] = '\0';
if (strcmp(cmd, "exit") == 0)
break;
else if (cmd[0] == '\0')
continue;
if (status == -1)
{
switch (errno)
{
case ENOENT:
write(STDERR_FD, "404:Command not found\n", strlen("404:Command not found\n"));
break;
case EACCES:
write(STDERR_FD, "Permission denied\n", strlen("Permission denied\n"));
break;
case ENOMEM:
write(STDERR_FD, "Insufficient memory\n", strlen("Insufficient memory\n"));
break;
default:
write(STDERR_FD, "Error\n", strlen("Error\n"));
break;
}
}
}
free(cmd);
return (0);
}
