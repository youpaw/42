//
// Created by Azzak Omega on 10/22/20.
//

#include "jobs.h"
#include "cc_vec.h"

int 	queue_get_last(void)
{
	int		index;

	if (g_job_queue->size > 2 && !vec_get_at(&index, g_job_queue,
										  g_job_queue->size - 3))
		return (index);
	return (-1);
}
