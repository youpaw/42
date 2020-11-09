//
// Created by Azzak Omega on 11/7/20.
//
#include "jobs.h"

char	get_status_sign_for_job(int job_index, int is_job_builtin)
{
	const int	cur_index = queue_get_current(is_job_builtin);
	const int	last_index = queue_get_last(is_job_builtin);

	if (job_index == cur_index)
		return ('+');
	if (job_index == last_index)
		return ('-');
	return (' ');
}
