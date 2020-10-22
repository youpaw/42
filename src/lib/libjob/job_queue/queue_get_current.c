//
// Created by Azzak Omega on 10/22/20.
//

#include "jobs.h"
#include "cc_vec.h"

int 	queue_get_current(void)
{
	int		index;

	if (!vec_get_last(&index, g_job_queue))
		return (index);
	return (-1);
}
