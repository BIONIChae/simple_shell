#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "unix.h"
#include "handle_ls.h"

#define STDOUT_FD 1
#define STDERR_FD 2
#define SHELL_NAME "hsh"

/**
* execute_cd - Changes the current working directory.
*
* @args: the command arguments.
* The directory path should be provided as args[1].
* Return: 0 on success, 1 on failure.
*/
int execute_cd(char *args[])
{
if (args[1] == NULL)
{
write(STDERR_FILENO, "cd: expected argument to \"cd\"\n", 31);
return (1);
}
if (chdir(args[1]) != 0)
{
perror("cd");
return (1);
}
return (0);
}

/**
* execute_cat - displays the contents of a file.
* @args: the command arguments. The file path should be provided as args[1].
* Return: 0 on success, 1 on failure.
*/
int execute_cat(char *args[])
{
int fd;
char buffer[1024];
ssize_t n;

if (args[1] == NULL)
{
write(STDERR_FILENO, "cat: missing operand\n", 21);
return (1);
}
fd = open(args[1], O_RDONLY);
if (fd == -1)
{
perror("cat");
return (1);
}
while ((n = read(fd, buffer, sizeof(buffer))) > 0)
{
write(STDOUT_FILENO, buffer, n);
}
close(fd);
return (0);
}

/**
* execute_pwd - prints the current working directory.
*
* Return: 0 on success, 1 on failure
*/
int execute_pwd(void)
{
char cwd[1024];
if (getcwd(cwd, sizeof(cwd)) != NULL)
{
write(STDOUT_FILENO, cwd, strlen(cwd));
write(STDOUT_FILENO, "\n", 1);
}
else
{
perror("pwd");
return (1);
}
return (0);
}

/**
* execute_echo - displays the provided arguments
* @args: the command arguments.
* The content to be displayed starts from args[1]
* Return: 0 on success, 1 on failure.
*/
int execute_echo(char *args[])
{
int i = 1;
while (args[i] != NULL)
{
write(STDOUT_FILENO, args[i], strlen(args[i]));
write(STDOUT_FILENO, " ", 1);
i++;
}
write(STDOUT_FILENO, "\n", 1);
return (0);
}

/**
* main - the entry point of the shell
* Return: 0 always
*/
int main(void)
{
size_t size = 0;
char *inputComm = NULL, *arg[6] = {NULL}, *value;
int status, counter = 0, i = 0;
while (1)
{
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
