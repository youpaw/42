#include "cc.h"
#include "expand.h"
#include <stdio.h>
#include "readline.h"

int main(int ac, char *av[], char *en[])
{
	t_letter res;
//	fdputs("Hello world!", 1);
//	printf("%lu", sizeof(t_list*));
	main_init();
	char *line = NULL;
	readline(&line);
//	res.num = getch();
//	write(STDOUT_FILENO, &res.ch, 4);
//	printf("\n%d, %d, %d, %d, %d", res.ch[0], res.ch[1], res.ch[2], res.ch[3], res.num);
	return_tty();
	return (0);
}
