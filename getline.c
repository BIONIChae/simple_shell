#include "unix.h"

/**
 * getline_from_scratch - A custom getline function.
 * @read_line: A double pointer which reads the input.
 * @buf_size: The size of the buffer.
 * @data_stream: Pointer to the file object.
 *
 * Return: 0 on success, -1 on failure.
 */
ssize_t getline_from_scratch(char **read_line,
		size_t *buf_size, FILE *data_stream)
{
	int count = 0, i;
	size_t sz = *buf_size * 2;
	char *updated_buf = malloc(sz);

	if (read_line == NULL || buf_size == NULL)
	{
		perror("1: An error has occured");
		exit(EXIT_FAILURE);
	}
	for (; read_line[count] != NULL; count++)
		;

	*buf_size = malloc(sizeof(char) * (count + 1));

	if (buf_size == NULL)
	{
		perror("1: malloc: process failed!\n");
		return (-1);
	}
	free(buf_size);
	return (0);
}
