#include <stdio.h>

int main(void)
{
	char *av[4] = {"program name", "av1", "av2", NULL};
	int count;

	for (count = 1; av[count] != NULL; count++)
		printf("%s\n", av[count]);

	return (0);
}
