#include "unix.h"

/**
 * split_str - Tokenises a string, without using strtok.
 * @str: The string to be split.
 * @delim: Marking point to split.
 *
 * Return: 0
 */
char split_str(char *str, char delim)
{
	int i = 0;
	char *tok = &str[i];

	if (str == NULL)
		exit(0);

	for (; *tok != '\0'; i++)
	{
		if (*tok == delim)
			break;
		write(STDOUT_FILENO, tok, strlen(tok));
		tok++;
	}
	write(STDOUT_FILENO, str, sizeof(str) - 1);
	return (0);
}
