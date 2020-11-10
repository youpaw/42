//
// Created by Halfhand Lorrine on 11/10/20.
//

#include "alias.h"
#include "cc_str.h"

void alias_usage_error_print(const char *cmd, int *er_code)
{
	*er_code = 2;
	puts(cmd);
	puts(": usage: ");
	puts(cmd);
	if (strcmp(cmd, "alias") == 0)
		puts(" [-p]");
	else
		puts(" [-a]");
	putendl(" name [name ...]");
}
