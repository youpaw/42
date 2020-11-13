//
// Created by Azzak Omega on 10/25/20.
//

#include "jobs.h"

void	remove_job_by_index(int job_index)
{
	t_job	*j;
	t_job	*jlast;
	t_job	*jnext;

	jlast = NULL;
	j = g_first_job;
	while (j)
	{
		jnext = j->next;
		if (j->index == job_index)
		{
			if (jlast)
				jlast->next = jnext;
			else
				g_first_job = jnext;
			free_job(&j);
			return ;
		}
		jlast = j;
		j = jnext;
	}
}
