//
// Created by Darth Butterwell on 11/7/20.
//
#include "jobs.h"
#include "env.h"

int		process_init(t_process *p)
{
	if (expand_ast(p->ast))
		return (1);
	p->argv = get_args(p->ast);
	prepare_exec_env(p->ast);
	p->env = exec_env_2array();
	exec_env_del();
	return (0);
}
