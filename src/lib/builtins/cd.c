//
// Created by Darth Butterwell on 8/23/20.
//

#include "builtins.h"
#include "stdio.h"
#include "cc.h"

char FLAG = '0';

static int check_ac(int ac, const char **av)
{
	if (ac > 3)
		putendl("too many arguments");
	else if (ac > 1 && *av[1] == '-')
}

int cd(int ac, const char **av)
{



	return (0);
}

