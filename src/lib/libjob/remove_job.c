//
// Created by Azzak Omega on 10/25/20.
//

#include "jobs.h"
#include <stdlib.h>

static void	free_job(t_job *j)
{
	free(j->command);
	del_process(j->first_process);
	queue_remove(j->index);
}

void	remove_job(int job_index)
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
			free_job(j);
			return ;
		}
		jlast = j;
		j = jnext;
	}
}
