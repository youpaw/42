//
// Created by Azzak Omega on 10/8/20.
//

#include "jobs.h"
#include <sys/wait.h>

void		update_status(void)
{
	int			status;
	pid_t		pid;
	const int	opt = WUNTRACED | WNOHANG;

	pid = waitpid(WAIT_ANY, &status, opt);
	while (!mark_process_status(pid, status))
		pid = waitpid(WAIT_ANY, &status, opt);
}
