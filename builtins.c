#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "unix.h"
#include "main.c"

/**
* setenv - initializes a new environment variable, or modifies an existing one.
* @variable: a named storage location that holds a value.
* @value: data stored in a variable
* @overwrite: replacing the existing value of a variable with a new value
* Return: 0 on success,1 on failure.
*/
int setenv(char *variable, char *value, int overwrite)
{
/*Check for the correct number of arguments*/
if (argc < 3)
{
write(2, "Usage: setenv VARIABLE VALUE\n", 33);
return (1);
}

/*Check if the variable already exists*/
if (getenv(variable) != NULL)
{
if (overwrite == 0)
{
write(2, "The variable '%s' already exists.\n", variable);
return (1);
}
}
int result = setenv(variable, value, 1);

if (result < 0)
{
perror("setenv");
return (1);
}
return (0);
}

/**
* unsetenv - removes an environment variable.
* @variable: a named storage location that holds a value.
* Return: 0 on success,1 on failure
*/
int unsetenv(char *variable)
{
/*Check for the correct number of arguments*/
if (argc < 2)
{
write(2, "Usage: unsetenv VARIABLE\n", 33);
return (1);
}
int result = unsetenv(variable);

if (result < 0)
{
perror("unsetenv");
return (1);
}

return (0);
}

/**
* cd - changes the current directory of the process.
* @argv: an array of strings containing the argument.
* Return: 0 on success,1 on failure
*/
int cd(char **argv)
{
/*Check for the correct number of arguments*/
if (argc < 1)
{
chdir(getenv("HOME"));
}
else if (strcmp(argv[1], "-") == 0)
{
chdir(getenv("OLDPWD"));
}
else
{
chdir(argv[1]);
}

/* Update the environment variable PWD*/
char cwd[PATH_MAX];
if (getcwd(cwd, sizeof(cwd)) == NULL)
{
perror("getcwd");
return (1);
}
setenv("PWD", cwd, 1);

return (0);
}

