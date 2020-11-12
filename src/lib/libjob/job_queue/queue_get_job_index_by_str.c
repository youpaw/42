//
// Created by Azzak Omega on 11/7/20.
//

#include "jobs.h"
#include "cc_str.h"

int	queue_get_job_index_by_str(const char *str)
{
	if (!str)
		return (queue_get_current(1));
	if (str[0] == '+')
		return (queue_get_current(1));
	if (str[0] == '-')
		return (queue_get_last(1));
	if (strisnum(str))
		return (atoi(str));
	return (-1);
}
