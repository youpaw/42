//
// Created by Azzak Omega on 10/6/20.
//

#include "jobs.h"

int		remove_job_by_index(size_t index)
{
	size_t 	i;
	size_t	list_size;
	t_job	job;

	i = 0;
	list_size = g_jobs.data->size;
	while (i < list_size)
	{
		vec_get_at(&job, g_jobs.data, i);
		if (job.id == index)
		{
			if (index == g_jobs.last_job_index)
				g_jobs.last_job_index--;
			vec_rm_at(g_jobs.data, i);
			return (0);
		}
		i++;
	}
	return (1);
}
