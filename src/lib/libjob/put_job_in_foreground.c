//
// Created by Azzak Omega on 10/8/20.
//

#include "jobs.h"
#include <signal.h>
#include <unistd.h>
#include "cc_str.h"

int		put_job_in_foreground(t_job *j, int cont)
{
	int		return_value;

	tcsetpgrp(g_terminal, j->pgid);
	if (cont)
	{
		putendl(j->command);
		tcsetattr(g_terminal, TCSADRAIN, &j->tmodes);
		if (kill(-j->pgid, SIGCONT) < 0)
			fdputendl("kill (SIGCONT)", 2);
	}
	return_value = wait_for_job(j, WUNTRACED);
	if (tcsetpgrp(g_terminal, g_pgid) < 0)
	{
		fdputendl("Terminal failed to return", 2);
		exit(1);
	}
	tcgetattr(g_terminal, &j->tmodes);
	tcsetattr(g_terminal, TCSADRAIN, &g_tmodes);
	return (return_value);
}
