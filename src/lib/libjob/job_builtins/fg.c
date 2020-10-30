//
// Created by Azzak Omega on 10/21/20.
//

#include "cc_str.h"
#include "jobs.h"
#include "error.h"

static int	put_job_in_fg(int index)
{
	t_job	*job;

	if (!(job = find_job_by_index(index)))
		return (1);
	queue_move_back(index);
	job->notified = 0;
	put_job_in_foreground(job, 1);
	return (0);
}


int 	fg(const char **av)
{
	int			index;
	const char	*error_args[3];

	error_args[0] = "fg";
	error_args[2] = NULL;
	putendl("fg builtin");
	index = -1;
	if (!av[1])
		index = queue_get_current(1);
	else
	{
		if (av[1][0] == '+')
			index = queue_get_current(1);
		else if (av[1][0] == '-')
			index = queue_get_last(1);
		else if (is_number(av[1]))
			index = atoi(av[1]);
	}
	if (put_job_in_fg(index))
	{
		error_args[1] = av[1] ? av[1] : "current";
		error_print(E_NOSUCHJOB, error_args);
	}
	return (0);
}
