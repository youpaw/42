//
// Created by Azzak Omega on 10/8/20.
//

#include "jobs.h"
#include <sys/wait.h>

int		wait_for_job(t_job *j, int options)
{
	int		status;
	pid_t	pid;

	if (!j)
		return (0);
	pid = waitpid(WAIT_ANY, &status, options);
	while (!mark_process_status(pid, status)
			&& !job_is_stopped(j)
			&& !job_is_completed(j))
		pid = waitpid(WAIT_ANY, &status, options);
	return (status);
}
