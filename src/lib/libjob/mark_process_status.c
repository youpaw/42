//
// Created by Azzak Omega on 10/8/20.
//

#include "jobs.h"
#include <sys/wait.h>

static int	set_process_status(t_process *p, int status)
{
	p->status = status;
	if (WIFCONTINUED(status))
		p->stopped = 0;
	if (WIFSTOPPED(status))
		p->stopped = 1;
	else
		p->completed = 1;
	return (0);
}

int			mark_process_status(pid_t pid, int status)
{
	t_job		*j;
	t_process	*p;

	if (!(j = g_first_job))
		return (1);
	if (pid > 0)
		while (j)
		{
			p = j->first_process;
			while (p)
			{
				if (p->pid == pid)
					return (set_process_status(p, status));
				p = p->next;
			}
			j = j->next;
		}
	return (-1);
}
