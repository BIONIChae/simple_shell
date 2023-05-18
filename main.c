#include "unix.h"

/**
 * main - The main function.
 * @ac: The arg count.
 * @av: arg vector.
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	char cmd_prompt[1060];

	while (1)
	{
		interpret("Enter your name: ");
	}
	return (0);
	handle_args(4, ("Joe", "Meghan", "Ryan", "Ben"));
	in_path("/root/bin/simple_shell");
	exiting();
	print_env();
	getline_from_scratch(&line, &buf_size, stdin);
	char str[] = "Hi, how are you? ";

	split_str(str, ' ');
	_exiting_();
	return (0);
}
