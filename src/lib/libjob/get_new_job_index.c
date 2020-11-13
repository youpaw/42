//
// Created by Azzak Omega on 10/22/20.
//

#include "jobs.h"

int		get_new_job_index(void)
{
	t_job	*tmp;

	if (!(tmp = g_first_job))
		return (1);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->index + 1);
}
