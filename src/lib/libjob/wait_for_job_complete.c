//
// Created by Darth Butterwell on 10/31/20.
//

#include "jobs.h"
#include <sys/wait.h>

/* Check for processes that have status information available,
   blocking until all processes in the given job have reported.  */

void	wait_for_job_complete(t_job *j)
{
	int status;
	pid_t pid;

	do
		pid = waitpid (WAIT_ANY, &status, WUNTRACED);
	while (!mark_process_status(pid, status)
		   && !job_is_completed (j));
}
