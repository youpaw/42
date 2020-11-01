//
// Created by Azzak Omega on 10/21/20.
//

#include "jobs.h"

int fg_builtin(const char **av)
{
	return (bg_fg(av, 1));
}
