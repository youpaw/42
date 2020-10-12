//
// Created by youpaw on 10/11/20.
//

#include "jobs.h"
#include <stddef.h>

/* Find the active job with the indicated pgid.  */
t_job	*find_job (pid_t pgid)
{
	t_job *j;

	for (j = g_first_job; j; j = j->next)
		if (j->pgid == pgid)
			return j;
	return NULL;
}