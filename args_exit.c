#include "unix.h"

/**
 * _exiting_ - Exits the shell using an int.
 * @count: The arg count.
 * @vec: Double pointer to the array of strings.
 *
 * Return: 0 on success.
 */
int _exiting_(int count, char **vec)
{
	int status = atoi(vec[1]);

	while (vec[count] != NULL)
	{
		write(STDOUT_FILENO, vec[count], strlen(vec[count]));
		count++;

	}
	if (count < 2)
	{
		perror("Error: Incorrect number of arguments\n");
		exit(status);
	}
	return (0);
}
