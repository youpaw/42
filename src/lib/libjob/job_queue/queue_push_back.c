//
// Created by Azzak Omega on 10/22/20.
//

#include "jobs.h"
#include "cc_vec.h"

void	queue_push_back(int index)
{
	vec_push(g_job_queue, (void *)&index);
}