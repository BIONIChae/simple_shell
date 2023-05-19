#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "unix.h"

/**
* my_setenv - initializes new environment variable,or modifies an existing one
* @variable: a named storage location that holds a value.
* @value: data stored in a variable.
* @overwrite: replacing the existing value of a variable with a new value.
* Return: 0 on success, 1 on failure.
*/
int my_setenv(const char *variable, const char *value, int overwrite)
{
int result;

/* Check for the correct number of arguments */
if (variable == NULL || value == NULL)
{
write(2, "Usage: setenv VARIABLE VALUE\n", 29);
return (1);
}

/* Check if the variable already exists */
if (getenv(variable) != NULL)
{
if (overwrite == 0)
{
write(2, "The variable '", 14);
write(2, variable, strlen(variable));
write(2, "' already exists.\n", 18);
return (1);
}
}
result = setenv(variable, value, 1);

if (result < 0)
{
perror("setenv");
return (1);
}

return (0);
}

/**
* my_unsetenv - removes an environment variable.
* @variable: a named storage location that holds a value.
* Return: 0 on success, 1 on failure.
*/
int my_unsetenv(const char *variable)
{
int result;
/* Check for the correct number of arguments */
if (variable == NULL)
{
write(2, "Usage: unsetenv VARIABLE\n", 25);
return (1);
}

result = unsetenv(variable);

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
* Return: 0 on success, 1 on failure.
*/
int cd(char **argv)
{
int result;
char cwd[4096];

/* Check for the correct number of arguments */
if (argv[1] == NULL)
{
chdir(getenv("HOME"));
}
else if (strcmp(argv[1], "-") == 0)
{
chdir(getenv("OLDPWD"));
}
else
{
if (chdir(argv[1]) != 0)
{
perror("cd");
return (1);
}
}

/* Update the environment variable PWD */
if (getcwd(cwd, sizeof(cwd)) == NULL)
{
perror("getcwd");
return (1);
}

result = my_setenv("PWD", cwd, 1);

if (result != 0)
{
return (1);
}

return (0);
}
