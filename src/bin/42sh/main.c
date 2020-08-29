#include "cc.h"
#include "expand.h"
#include <stdio.h>
#include "readline.h"

int main(int ac, char *av[], char *en[])
{
	t_letter res;

	tty_init();
	char *line = NULL;
	if (ac == 2)
	{
		if (strcmp(av[1], "-c") == 0)
		{
		res.num = getch();
		write(STDOUT_FILENO, &res.ch, 4);
		printf("\n\\%o, \\%o, \\%o, \\%o, %d", res.ch[0], res.ch[1], res.ch[2], res.ch[3], res.num);
			restore_tty();
		return (0);
		}
	}
	readline(&line);
	restore_tty();
	return (0);
}
