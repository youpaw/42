//
// Created by youpaw on 10/11/20.
//

#include "jobs.h"


/* Return true if all processes in the job have completed.  */
int	job_is_completed (t_job *j)
{
	t_process *p;

	for (p = j->first_process; p; p = p->next)
		if (!p->completed)
			return 0;
	return 1;
}
