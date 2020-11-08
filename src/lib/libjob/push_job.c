//
// Created by Azzak Omega on 10/17/20.
//

#include "jobs.h"

int		push_job(t_job *job)
{
	t_job	*tmp;

	if (!job)
		return (-1);
	if (!g_first_job)
		g_first_job = job;
	else
	{
		tmp = g_first_job;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = job;
	}
	return (0);
}
