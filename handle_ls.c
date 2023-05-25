#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "unix.h"
#include "handle_ls.h"

/**
* execute_ls - executes the "ls" command
* to list the contents of the current directory.
*
* Return: 0 on success, or 1 on failure.
*/
int execute_ls(void)
{
DIR *dir;
struct dirent *entry;

dir = opendir(".");
if (dir == NULL)
{
perror("ls");
return (1);
}

while ((entry = readdir(dir)) != NULL)
{
write(STDOUT_FILENO, entry->d_name, strlen(entry->d_name));
write(STDOUT_FILENO, "\n", 1);
}

closedir(dir);
return (0);
}
