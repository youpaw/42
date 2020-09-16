//
// Created by Azzak Omega on 9/16/20.
//

#include <stdlib.h>
#include "cc_char.h"
#include "cc_num.h"
#include "error.h"

static int	is_numeric(const char *nb)
{
	if (*nb == '+' || *nb == '-')
		nb++;
	while (*nb)
		if (!isdigit(*nb++))
			return (0);
	return (1);
}

int 	sh_exit(const char **args)
{
	if (!args[1])
		exit(0);
	else if (!is_numeric(args[1]))
	{
		error_print(E_NUMARGREQ, args);
		exit(255);
	}
	else if (!args[2])
		exit(atoi(args[1]));
	else
		error_print(E_TOOMANYARGS, args);
	return (0);
}
