//
// Created by Azzak Omega on 10/8/20.
//

#include "jobs.h"
#include "cc_str.h"
#include <stdlib.h>


/* Notify the user about stopped or terminated jobs.
   Delete terminated jobs from the active job list.  */

void	do_job_notification(void)
{
	t_job *j, *jlast, *jnext;

	update_status();
	jlast = NULL;
	for (j = g_first_job; j; j = jnext)
	{
		jnext = j->next;
		/* If all processes have completed, tell the user the job has
		   completed and delete it from the list of active jobs.  */
		if (job_is_completed(j))
		{
			//if (!j->notified)
			print_job_formatted(j, 0, JPM_DEFAULT);
			if (jlast)
				jlast->next = jnext;
			else
				g_first_job = jnext;
			free_job(&j);
		}
		else if (job_is_stopped(j) && !j->notified)
		{
            print_job_formatted(j, 0, JPM_DEFAULT);
			j->notified = 1;
			jlast = j;
		}
		else
			jlast = j;
	}
}