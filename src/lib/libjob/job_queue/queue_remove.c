//
// Created by Azzak Omega on 10/22/20.
//

#include "jobs.h"
#include "cc_vec.h"

void	queue_remove(int index)
{
	size_t	i;
	int		found_index;

	i = 0;
	while (i < g_job_queue->size)
	{
		vec_get_at(&found_index, g_job_queue, i);
		if (index == found_index)
		{
			vec_rm_at(g_job_queue, i);
			break ;
		}
		i++;
	}
}
