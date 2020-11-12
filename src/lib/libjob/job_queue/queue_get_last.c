//
// Created by Azzak Omega on 10/22/20.
//

#include "jobs.h"
#include "cc_vec.h"

int		queue_get_last(int is_job_builtin)
{
	int		index;
	int		queue_size;

	queue_size = (int)g_job_queue->size - is_job_builtin;
	if (queue_size > 1 && !vec_get_at(&index, g_job_queue,
									queue_size - 2))
		return (index);
	return (-1);
}
