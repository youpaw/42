//
// Created by Azzak Omega on 10/17/20.
//

#include "jobs.h"
#include "cc_str.h"

void	free_processes(t_process *p)
{
	if (!p)
		return ;
	free(p->argv);
	strarr_del(p->env);
	free(p->env);
	free_processes(p->next);
	free(p->next);
}