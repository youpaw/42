//
// Created by Azzak Omega on 10/6/20.
//
#include "jobs.h"
#include <sys/types.h>
#include <sys/wait.h>
#include "cc_str.h"
#include "cc_num.h"


void	check_jobs(void)
{
	int		status;
	pid_t	pid;

	print_process_stats("Check jobs");
	if ((pid = waitpid(-1, &status, WNOHANG | WUNTRACED)) > 0)
	{
		if (!remove_job_by_pid(pid))
		{
			putnbr(pid);
			putendl(" job terminated");
		}
	}
	else
	{
		putendl("No jobs terminated");
	}
}