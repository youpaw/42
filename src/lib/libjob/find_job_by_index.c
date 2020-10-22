//
// Created by Azzak Omega on 10/22/20.
//

#include "jobs.h"

t_job	*find_job_by_index(int index)
{
	t_job *j;

	if (index < 1)
		return (NULL);
	for (j = g_first_job; j; j = j->next)
		if (j->index == index)
			return (j);
	return (NULL);
}
