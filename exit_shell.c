#include "unix.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
* exiting - Exits the shell
* Return: 0
*/
int exiting(void)
{
char *commands[] = { "Command 1", "Command 2", "Command 3" };
int numCommands = sizeof(commands) / sizeof(commands[0]);
int i, status;
pid_t pid;
char *args[2];
for (i = 0; i < numCommands; i++)
{
pid = fork();
if (pid == -1)
{
char *cmd = "./hsh";
write(STDERR_FILENO, cmd, strlen(cmd));
write(STDERR_FILENO, ": Fork failed\n", 14);
exit(EXIT_FAILURE);
}
if (pid == 0)
{
char *cmd = strrchr(commands[i], '/');
if (cmd == NULL)
cmd = commands[i];
else
cmd += 1;
args[0] = cmd;
args[1] = NULL;
execve(commands[i], args, NULL);
write(STDERR_FILENO, cmd, strlen(cmd));
write(STDERR_FILENO, ": 1: ", 5);
write(STDERR_FILENO, commands[i], strlen(commands[i]));
write(STDERR_FILENO, ": not found\n", 12);
_exit(EXIT_FAILURE);
waitpid(pid, &status, 0);
if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
{ /* Handle success case here */
}
else
{ /* Handle failure case here */ }
}
}
return (0);
}
