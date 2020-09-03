#include "cc.h"
#include "expand.h"
#include <stdio.h>
#include "readline.h"

int main(int ac, char *av[], char *en[])
{
	t_letter res;
	int len;
	char *line = NULL;

	tty_init();
	if (ac == 2)
	{
		;
	}
	readline(&line);
	puts("\n");
	puts(line);
	restore_tty();
	return (0);
}
