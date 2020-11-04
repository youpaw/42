//
// Created by Azzak Omega on 11/3/20.
//

#include "jobs.h"

void	free_all_jobs(void)
{
	t_job	*j;
	t_job	*next_job;

	j = g_first_job;
	while (j)
	{
		next_job = j->next;
		free_job(&j);
		j = next_job;
	}
}