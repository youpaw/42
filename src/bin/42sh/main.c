#include "cc.h"
#include <stdio.h>
#include "readline.h"
#include "history.h"

//int main(int ac, char *av[], char *en[])
//{
//	char *str;
//
//	 hist_init("/Users/azomega");
//	hist_print();
//	str = strdup("un");
//	expand_bang(&str);
//	putendl(str);
//	return (0);
//}

int main(int ac, char *av[], char *en[])
{
	t_letter res;
	int len;
	char *line = "asd";

	tty_init();
	hist_init("/Users/azomega");
	signal_init();
	if (ac == 2)
	{
		res.num = getch();
		len = get_displayed_symbol_len(res.uch);
		write(1, res.ch, 4);
		printf("  %d\n", len);
	}
	else
	{
		readline(&line);
		puts("\n");
		puts(line);
	}
	tty_restore();
	return (0);
}
