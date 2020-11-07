//
// Created by Halfhand Lorrine on 10/31/20.
//

#include "alias_builtins.h"

void		alias_error_print(const char *cmd)
{
		puts(cmd);
		puts(": usage: ");
		puts(cmd);
		if (strcmp(cmd, "alias") == 0)
			puts(" [-p]");
		else
			puts(" [-a]");
		putendl(" name [name ...]");
}