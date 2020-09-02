
#include "main.h"

int main(int ac, const char *av[], const char *en[])
{
	int error;

	if (!(error = main_init(av[0], av + 1, en)))
		error = main_manager();
	return (error);
}
