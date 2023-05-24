#include "unix.h"

/**
 * in_path - Handles the path.
 * @path: The path given.
 *
 * Return: 0 on success, no-zero on failure.
 */
int in_path(char *path)
{
	char *element;
	pid_t process_ID = fork();
	char *buf;

	if (path == NULL)
	{
		perror("1: path: not found");
		exit(EXIT_FAILURE);
	}

	if (process_ID < 0)
	{
		perror("1: fork: error occured");
		return (1);
	}
	else if (process_ID == 0)
	{
		element = strtok(path, "/");
		while (element != NULL)
		{
			if (access(element, X_OK) == 0)
			{
				buf = "Is an executable\n";
				write(STDOUT_FILENO, buf, strlen(buf));
				;
			}
			element = strtok(NULL, "/");
		}
		buf = "1: Executable: not found\n";
		write(STDOUT_FILENO, buf, strlen(buf));
		return (-1);
	}
	wait(NULL);
	return (0);
}
