//
// Created by Darth Butterwell on 10/31/20.
//

#include "jobs.h"
#include <sys/wait.h>

/* Check for processes that have status information available,
   blocking until all processes in the given job have reported.  */

/*
static int		update_job_status(t_job *j)
{
	t_process *p;

	while
}
*/
void	wait_for_job_complete(t_job *j)
{
	int status;
	pid_t pid;

	while (!job_is_completed(j))
	{
		pid = waitpid(WAIT_ANY, &status, WUNTRACED);
		mark_process_status(pid, status);
	}
}
