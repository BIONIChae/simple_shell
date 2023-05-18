#include "unix.h"

/**
 * exiting - Exits the shell.
 *
 * Return: 0
 */
int exiting(void)
{
	if (STDIN_FILENO < 0)
	{
		perror("Error: stdin: Does not exist\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
