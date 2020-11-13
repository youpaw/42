//
// Created by Darth Butterwell on 11/7/20.
//
#include "jobs.h"

int		process_init(t_process *p)
{
	if (expand_ast(p->ast))
		return (1);
	p->argv = get_args(p->ast);
	return (0);
}
