#include "unix.h"

/**
 * interpret - Runs a unix command-line interpreter.
 * @cmd_input: The user input.
 *
 * Return: 0
 */
int interpret(char *cmd_input)
{
	size_t buffer = 0;
	int run = 1, count = 0;

	for (; cmd_input[count] != '\0'; count++)
	{
		if (count > 1)
			exit(EXIT_FAILURE);
	}

	while (run)
	{
		write(STDOUT_FILENO, "simple_shell > ", strlen("simple_shell > ") - 1);
		fflush(stdout);

		if (getline(&cmd_input, &buffer, STDIN_FILENO) == EOF)
		{
			perror("An error has occured\n");
			exit(EXIT_FAILURE);
		}
		if (cmd_input == NULL)
		{
			perror("Error: malloc: Failure allocating memory");
			return (-1);
		}
		if (access(cmd_input, X_OK) < 0)
		{
			perror("Error: Executable not found\n");
			continue;
		}
		free(cmd_input);
		cmd_input = NULL;
	}
	free(cmd_input);
	return (0);
}
