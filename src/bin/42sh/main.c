#include "cc.h"
#include "expand.h"

int main(int ac, char *av[], char *en[])
{
//	fdputs("Hello world!", 1);
//	return (0);

//	char *str = strdup("aaa  \"bb \\\n $((\\\nHOME\\\n)) vvv\" 'aaa \\\n bbbbb' ");
//	int error = handle_raw(&str, e_validate);
//	fdputs(str, 1);
//	free(str);
//	exit(error);
	main_init();
	readline(NULL);
	return_tty();
}
