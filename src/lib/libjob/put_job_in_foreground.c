//
// Created by Azzak Omega on 10/8/20.
//


#include "jobs.h"
#include <signal.h>
#include <unistd.h>
#include "cc_str.h"
#include "cc_num.h"

/* Put job j in the foreground.  If cont is nonzero,
   restore the saved terminal modes and send the process group a
   SIGCONT signal to wake it up before we block.  */

void	put_job_in_foreground (t_job *j, int cont)
{
	tcsetpgrp(g_terminal, j->pgid);
	/* Send the job a continue signal, if necessary.  */
	if (cont)
	{
		putendl(j->command);
		tcsetattr (g_terminal, TCSADRAIN, &j->tmodes);
		if (kill (-j->pgid, SIGCONT) < 0)
			fdputendl("kill (SIGCONT)", 2);
	}
	wait_for_job(j);
	/* Put the shell back in the foreground.  */
	//signal(SIGTTOU, SIG_IGN);
	//setpgid(getpid(), j->pgid);
	//if (job_is_completed(j))
	//	j->notified = 1;
	if( tcsetpgrp (g_terminal, g_pgid) < 0)
	{
		fdputendl("Terminal failed to return", 2);
		exit(1);
	}
	/* Restore the shell’s terminal modes.  */
	tcgetattr (g_terminal, &j->tmodes);
	tcsetattr (g_terminal, TCSADRAIN, &g_tmodes);
}
