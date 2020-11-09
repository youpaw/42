//
// Created by Darth Butterwell on 10/31/20.
//

#include "jobs.h"
#include <sys/wait.h>
#include <signal.h>
#include "cc_str.h"

int		wait_for_job_complete(t_job *j)
{
	int		status;
	pid_t	pid;

	while (!job_is_completed(j))
	{
		pid = waitpid(WAIT_ANY, &status, WUNTRACED);
		mark_process_status(pid, status);
		if (WIFSTOPPED(status))
		{
			if (kill(-j->pgid, SIGSTOP) < 0)
				fdputendl("kill (SIGSTOP)", 2);
		}
	}
	return (status);
}
