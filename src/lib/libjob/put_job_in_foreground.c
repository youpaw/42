//
// Created by Azzak Omega on 10/8/20.
//


#include "jobs.h"
#include <signal.h>
#include <unistd.h>
#include "cc_str.h"

/* Put job j in the foreground.  If cont is nonzero,
   restore the saved terminal modes and send the process group a
   SIGCONT signal to wake it up before we block.  */

void	put_job_in_foreground (t_job *j, int cont)
{
	/* Put the job into the foreground.  */
	tcsetpgrp(g_terminal, j->pgid);
	//putendl("job putted in fg");

	/* Send the job a continue signal, if necessary.  */
	if (cont)
	{
		tcsetattr (g_terminal, TCSADRAIN, &j->tmodes);
		if (kill (- j->pgid, SIGCONT) < 0)
			fdputendl("kill (SIGCONT)", 2);
	}

	/* Wait for it to report.  */
	wait_for_job(j);
	//putendl("job wait ended");

	/* Put the shell back in the foreground.  */
	//tcsetpgrp (g_terminal, g_pgid);
	//setpgid(getpid(), j->pgid);
	signal(SIGTTOU, SIG_IGN);
	//print_process_stats("before");
	if( tcsetpgrp (g_terminal, g_pgid) < 0)
	{
		fdputendl("terminal failed to return", 2);
		exit(1);
	}
	//putendl("shell putted in fg");

	/* Restore the shell’s terminal modes.  */
	tcgetattr (g_terminal, &j->tmodes);
	tcsetattr (g_terminal, TCSADRAIN, &g_tmodes);
	//putendl("shell tmode restorred");
}
