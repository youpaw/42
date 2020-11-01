//
// Created by Azzak Omega on 10/8/20.
//

#include "jobs.h"
#include <sys/wait.h>


static int	set_process_status(t_process *p, int status)
{
	p->status = status;
	//if (WIFCONTINUED(status))
	//	p->stopped = 0;
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

//int		mark_process_status (pid_t pid, int status)
//{
//	t_job *j;
//	t_process *p;
//
//	if (pid > 0)
//	{
//		/* Update the record for the process.  */
//		for (j = g_first_job; j; j = j->next)
//			for (p = j->first_process; p; p = p->next)
//				if (p->pid == pid)
//				{
//					p->status = status;
//
//					//printf("\n exit status=%d\n\n", p->status);
//					if (WIFSTOPPED (status))
//						p->stopped = 1;
//					else
//					{
//						p->completed = 1;
//						if (WIFSIGNALED(status))
//							fprintf (stderr, "%d: Terminated by signal %d.\n",
//									 (int) pid, WTERMSIG (p->status));
//					}
//					return 0;
//				}
//		fprintf (stderr, "No child process %d.\n", pid);
//		return -1;
//	}
//	else if (pid == 0 || errno == ECHILD)
//		/* No processes ready to report.  */
//		return -1;
//	else {
//		/* Other weird errors.  */
//		perror ("waitpid");
//		return -1;
//	}
//}
//
