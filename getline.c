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
		size_t *size_of_buf)
{
	int count = 0;
	size_t sz = size_of_buf * 2;

	if (read_line == NULL || size_of_buf == NULL)
	{
		perror("1: An error has occured");
		exit(EXIT_FAILURE);
	}
	for (; read_line[count] != NULL; count++)
		;

	size_of_buf = malloc(sizeof(char) * (count + 1));

	if (size_of_buf == NULL)
	{
		perror("1: malloc: process failed!\n");
		return (-1);
	}
	free(size_of_buf);
	return (0);
}
