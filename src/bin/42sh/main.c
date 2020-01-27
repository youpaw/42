#include "cc.h"
#include "history_tests.h"
#include "history.h"
#include <stdio.h>




int main(int ac, char *av[], char *en[])
{
	fdputs("Hello, 42sh!\n", 1);
	test_history();
	return (0);
}
