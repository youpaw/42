#include "cc.h"
#include "history_tests.h"
#include "history.h"
#include <stdio.h>




int main(int ac, char *av[], char *en[])
{

	////char a[] = "1";
	//char *a = "1";
	//char *str;
	//str = strstr2("", a);
	//str = strstr("", "");
	//str = strstr("1", "");
	//str = strstr("", "1");
	//str = strstr("1", "2");
	//str = strstr("1", "1");
	//str = strstr(a, "");
	//str = strstr("1", a);// Invalid write of size 4
	//str = strstr("", a);// Invalid write of size 4

	fdputs("Hello, 42sh!\n", 1);
	test_history();
	return (0);
}
