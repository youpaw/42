#include "cc.h"
#include "expand.h"
#include <stdio.h>
#include "readline.h"
#include "history.h"
#include "expand.h"

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
	char *line = NULL;

	tty_init();
	hist_init("/Users/azomega");
	if (ac == 2)
	{
		;
	}
	readline(&line);
	puts("\n");
	puts(line);
	tty_restore();
	return (0);
}
