//
// Created by Azzak Omega on 10/8/20.
//

#include "jobs.h"

void	notify_and_remove_completed_job(t_job *j)
{
	if (!j->is_fg)
		print_job_formatted(j, 0, JPM_DEFAULT);
	remove_job_by_index(j->index);
}

void	do_job_notification(void)
{
	t_job	*j;
	t_job	*jnext;

	update_status();
	j = g_first_job;
	while (j)
	{
		jnext = j->next;
		if (job_is_completed(j))
			notify_and_remove_completed_job(j);
		else if (job_is_stopped(j) && !j->notified)
		{
            print_job_formatted(j, 0, JPM_DEFAULT);
			j->notified = 1;
		}
		j = jnext;
	}
}