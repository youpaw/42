//
// Created by Darth Butterwell on 11/9/20.
//

#include "jobs.h"
#include "env.h"

int run_builtin(t_process *p)
{
	int index;

	if ((index = get_builtin_index(p->argv[0])) != -1)
		return (run_builtin_by_index(p, index));
	return (-1);
}