//
// Created by Azzak Omega on 10/21/20.
//

#include "cc_str.h"
#include "jobs.h"

static int	put_job_in_fg(int pgid)
{
	t_job	*job;

	if (!(job = find_job(pgid)))
		return (1);
	put_job_in_foreground(job, 1);
	return (0);
}


int 	fg(const char **av)
{
	int	pgid;
	putendl("fg builtin");
	if (av[1])
	{
		pgid = atoi(av[1]);
		// need some checks because of atoi
		if (put_job_in_fg(pgid))
		{
			fdputs("fg: ", 2);
			fdputs(av[1], 2);
			fdputendl(": no such job", 2);
		}
	}
	//strarr_print(av, "|", "|\n");
	return (0);
}
