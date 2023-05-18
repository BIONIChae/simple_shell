#include "unix.h"

/**
 * handle_args - Handles lines with arguments.
 * @count: The argument count.
 * @vec: Double pointer to an array of strings.
 *
 * Return: 0
 */
int handle_args(int count, char **vec)
{
	int len = 1;

	if (count < 2)
	{
		perror("Invalid number of arguments\n");
		exit(EXIT_FAILURE);
	}

	for (; len < count; len++)
	{
		write(STDOUT_FILENO, vec[len], sizeof(vec[len]));
	}
	return (0);
}
