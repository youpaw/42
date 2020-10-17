//
// Created by Azzak Omega on 10/17/20.
//

#include "jobs.h"
#include "cc_str.h"

void	del_process(t_process *p)
{
	if (!p)
		return ;
	free(p->argv);
	strarr_del(p->env);
	free(p->env);
	del_process(p->next);
	free(p->next);
}