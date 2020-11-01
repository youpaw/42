//
// Created by Azzak Omega on 10/22/20.
//

#include "jobs.h"
#include "cc_vec.h"

void	queue_move_back(int index)
{
	int		last_index;

	if (!vec_get_last(&last_index, g_job_queue) && last_index == index)
		return ;
	queue_remove(index);
	queue_push_back(index);
}
