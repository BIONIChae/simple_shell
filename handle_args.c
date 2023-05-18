#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "unix.h"
#include "main.c"

/**
*  handle_variables - replace variables in a string with their values.
*  @args: command line argument value
*  Return: 0 on success,1 on failure.
*/
int handle_variables(char **args)
{

/*Check if the user has provided any arguments*/
if (args[0] == NULL)
{
/*If not, do nothing*/
return (0);
}

/*For each argument, replace any variables with their values*/
for (int i = 0; args[i] != NULL; i++)
{
char *arg = args[i];
while (strchr(arg, '$') != NULL)
{
char *variable = strchr(arg, '$');
char *value = getenv(variable + 1);
if (value != NULL)
{
/*Replace the variable with its value*/
memmove(variable, value, strlen(value) + 1);
}
}
}

return (0);
}

/**
* handle_comments - remove comments from a string
* @args : command line argument value
* Return: 0 on success,1 on failure.
*/
int handle_comments(char **args)
{

/*Check if the user has provided any arguments*/
if (args[0] == NULL)
{
/*If not, do nothing*/
return (0);
}
/*For each argument, remove any comments*/
for (int i = 0; args[i] != NULL; i++)
{
char *arg = args[i];
while (strchr(arg, '#') != NULL)
{
/*Replace the comment with a null character*/
*strchr(arg, '#') = '\0';
}
}

return (0);
}

/**
*  handle_command_file - executes the commands in a file
*  @filename: name of command file
*  Return: 0 on success,1 on failure.
*/
int handle_command_file(char *filename)
{

/* Open the command file*/
FILE *file = fopen(filename, "r");
if (file == NULL)
{
/*If the file does not exist, print an error message*/
perror("fopen");
return (1);
}
/*Read each line from the file and execute it*/
char line[1024];
while (fgets(line, 1024, file) != NULL)
{
/*Strip the newline character from the end of the line*/
line[strlen(line) - 1] = '\0';

/*Handle variables and comments*/
handle_variables(&line);
handle_comments(&line);

/*Execute the command*/
int ret = system(line);
if (ret != 0)
{
perror("system");
return (1);
}
}

/* Close the file */
fclose(file);

return (0);
}
