#include "cc.h"
#include "expand.h"

int main(int ac, char *av[], char *en[])
{
//	fdputs("Hello world!", 1);
//	return (0);

	char *str = strdup("\"\\\n\"");
	int error = expand_raw(&str, e_exec);
	fdputs(str, 1);
	free(str);
	exit(error);
}
