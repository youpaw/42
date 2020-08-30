#include "cc.h"
#include "expand.h"
#include <stdio.h>
#include "readline.h"
#include "history.h"
#include "expand.h"

int main(int ac, char *av[], char *en[])
{
	char *str;

	hist_init("/Users/azomega");
	hist_print();
	str = strdup("un");
	expand_bang(&str);
	putendl(str);
	return (0);
}
/*
int main(int ac, char *av[], char *en[])
{
	t_letter res;
	int len;
	char *line = NULL;

	tty_init();
	if (ac == 2)
	{
		if (strcmp(av[1], "-c") == 0)
		{

		res.num = getch();
		write(STDOUT_FILENO, &res.ch, 4);
		len = get_displayed_symbol_len(res.ch);
		printf("\n\\%x, \\%x, \\%x, \\%x, unum: %u len: %d\n", res.uch[0], res.uch[1], res.uch[2], res.uch[3], res.unum, len);

		restore_tty();
		return (0);
		}
	}
	readline(&line);
	restore_tty();
	return (0);
}
*/