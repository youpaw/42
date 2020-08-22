#include "cc.h"
#include "expand.h"
#include <stdio.h>
#include "readline.h"

int main(int ac, char *av[], char *en[])
{
//	fdputs("Hello world!", 1);
//	printf("%lu", sizeof(t_list*));
	main_init();
	char *line = NULL;
	readline(&line);
	return_tty();
	return (0);
}
