#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "unix.h"

#define SHELL_NAME "hsh"
#define MAX_ARGS 1024

/**
* main - entry point
* @argv: an array of strings containing the arguments
* @argc: the number of command line arguments
* Return: 0 on succes,1 on failure
*/
int main(int argc, char **argv)
if (argc == 1)
{
}
else
{
execute_command(argv[1]);
}

return 0;
}

void interactive_shell() {
char line[MAX_ARGS];

while (1) {
printf("($) ");
fgets(line, MAX_ARGS, stdin);

line[strlen(line) - 1] = '\0';

execute_command(line);
}
}

void execute_command(char *command) {
// Split the command into arguments.
char **args = malloc(sizeof(char *) * MAX_ARGS);
int num_args = 0;

for (char *token = strtok(command, " "); token != NULL; token = strtok(NULL, " ")) {
args[num_args++] = token;
}
if (strcmp(args[0], "cd") == 0) {
cd(args[1]);
} else if (strcmp(args[0], "pwd") == 0) {
pwd();
} else if (strcmp(args[0], "exit") == 0) {
exit(0);
} else {
int ret = execvp(args[0], args);

if (ret == -1) {
write(2, "Command not found\n", 14);
exit(1);
}
}

free(args);
}

void cd(char *dir) {
if (chdir(dir) == -1) {
write(2, "Directory not found\n", 17);
return;
}

char cwd[1024];
getcwd(cwd, sizeof(cwd));
}

void pwd() {
char cwd[1024];
getcwd(cwd, sizeof(cwd));
write(1, cwd, strlen(cwd));
write(1, "\n", 1);
}
