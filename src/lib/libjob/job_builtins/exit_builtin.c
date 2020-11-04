//
// Created by Azzak Omega on 9/16/20.
//

#include <stdlib.h>
#include "cc_char.h"
#include "cc_num.h"
#include "error.h"
#include "jobs.h"
#include "cc_str.h"

static int	is_numeric(const char *nb)
{
	if (*nb == '+' || *nb == '-')
		nb++;
	while (*nb)
		if (!isdigit(*nb++))
			return (0);
	return (1);
}

int exit_builtin(const char **av)
{
	if (!av[1])
		exit_shell(0);
	else if (!is_numeric(av[1]))
	{
		error_print(E_NUMARGREQ, av);
		exit_shell(255);
	}
	else if (!av[2])
		exit_shell(atoi(av[1]));
	else
		error_print(E_TOOMANYARGS, av);
	return (0);
}
