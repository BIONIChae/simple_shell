#include "unix.h"
#define SHELL_NAME "hsh"

/**
* main - The main function.
*
* Return: 0
*/

int main(void)
{
char *cmd;
size_t size = 0;
while (1)
{
write(STDOUT_FILENO, "Enter a command: ", strlen("Enter a command: ");
getline(&cmd, &size, stdin);
if (cmd[strlen(cmd) - 1] == '\n')
{
cmd[strlen(cmd) - 1] = '\0';
}
if (strcmp(cmd, "exit") == 0)
{
break;
}
else if (cmd[0] == '\0')
{
continue;
}
int status = execve(cmd, NULL, NULL);
if (status != 0)
{
int errnum = errno;
switch (errnum)
{
case ENOENT:
write(2, "Error: command not found\n", 17);
break;
case EACCES:
write(2, "Permission denied\n", 16);
break;
case ENOMEM:
write(2, "Insufficient memory\n", 13);
break;
default:
write(2, "An unknown error has been detected\n", 12);
break;
}
}
}
return (0);
}
