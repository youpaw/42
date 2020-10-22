//
// Created by Azzak Omega on 10/22/20.
//

#include "jobs.h"
#include "cc_vec.h"
#include "cc_str.h"
#include "cc_num.h"

void	queue_print(void)
{
	int		index;
	size_t	i;

	i = 0;
	while (i < g_job_queue->size)
	{
		vec_get_at(&index, g_job_queue, i);
		putnbr(index);
		putendl("");
		i++;
	}
}
