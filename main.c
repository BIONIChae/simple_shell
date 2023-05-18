#include "unix.h"

/**
* main - The main function.
*
* Return: 0
*/

int main(void)
{
char *command;
size_t size = 0;
while (1)
{
write(STDOUT_FILENO, "Enter a command: ", strlen("Enter a command: ");
getline(&command, &size, stdin);
if (command[strlen(command) - 1] == '\n')
{
command[strlen(command) - 1] = '\0';
}
if (strcmp(command, "exit") == 0)
{
break;
}
else if (command[0] == '\0')
{
continue;
}
int status = execve(command, NULL, NULL);
if (status != 0)
{
int errnum = errno;
switch (errnum)
{
case ENOENT:
write(2, "Command not found\n", 17);
break;
case EACCES:
write(2, "Permission denied\n", 16);
break;
case ENOMEM:
write(2, "Out of memory\n", 13);
break;
default:
write(2, "Unknown error\n", 12);
break;
}
}
}
return (0);
}
