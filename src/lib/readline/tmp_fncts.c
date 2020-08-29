#include "readline.h"

char *vect_to_str(t_vec *vector, int size)
{
	char line[4];
	int i = 0;

	putchar('\n');
	while (i != size)
	{
		vec_get_at(line, vector, i++);
		write(STDOUT_FILENO, line, 4);
	}
	return NULL;
}
