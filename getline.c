#include <stdlib.h>
#include <stdio.h>
#include "unix.h"

/**
* getline_from_scratch - A custom getline function.
* @read_line: A double pointer which reads the input.
* @size_of_buf: The size of the buffer.
*
* Return: 0 on success, -1 on failure.
*/

ssize_t getline_from_scratch(char **read_line, size_t *size_of_buf)

{
int count;
char *new_buffer;

if (read_line == NULL || size_of_buf == NULL)
{
perror("1: An error has occurred");
exit(EXIT_FAILURE);
}

for (count = 0; (*read_line)[count] != '\0'; count++)
{
}

*size_of_buf = sizeof(char) * (count + 1);
new_buffer = malloc(*size_of_buf);

if (new_buffer == NULL)
{
perror("1: malloc: process failed!\n");
return (-1);
}

free(*read_line);
*read_line = new_buffer;
return (0);
}
