//
// Created by Darth Butterwell on 11/10/20.
//

#include "jobs.h"
#include "env.h"

int		run_builtin_by_index(t_process *p, int index)
{
	int err_code;

	prepare_exec_env(p->ast);
	err_code = exec_builtin_by_index((const char **) p->argv, index);
	free(p->argv);
	p->argv = NULL;
	exec_env_del();
	return (err_code);
}
