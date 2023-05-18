#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "unix.h"
#include "shell.c"

/**
* alias - define or display aliases
* @args: arguments passed
* Return:0 on success,1 on failure
*/
int alias(char **args)
{

/*Check if the user has provided any arguments.*/
if (args[1] == NULL)
{
/*If not, print a list of all aliases.*/
for (char **alias = environ; *alias != NULL; alias++)
{
if (strncmp(*alias, "alias=", 6) == 0)
{
puts(*alias);
}
}
}
else
{
/*If the user has provided arguments, define an alias for each argument.*/
for (int i = 1; args[i] != NULL; i++)
{
/*Check if the alias already exists.*/
char *alias_name = args[i];
char *alias_value = args[i + 1];
if (getenv(alias_name) != NULL)
{
/*If the alias already exists, replace its value.*/
setenv(alias_name, alias_value, 1);
}
else
{
/* If the alias does not already exist, define it.*/
setenv(alias_name, alias_value, 1);
}
}
}

return (0);
}
