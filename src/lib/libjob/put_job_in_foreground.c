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

void	put_job_in_foreground (job *j, int cont)
{
	/* Put the job into the foreground.  */
	tcsetpgrp(shell_terminal, j->pgid);

	/* Send the job a continue signal, if necessary.  */
	if (cont)
	{
		tcsetattr (shell_terminal, TCSADRAIN, &j->tmodes);
		if (kill (- j->pgid, SIGCONT) < 0)
			fdputendl("kill (SIGCONT)", 2);
	}

	/* Wait for it to report.  */
	wait_for_job(j);

	/* Put the shell back in the foreground.  */
	tcsetpgrp (shell_terminal, shell_pgid);

	/* Restore the shell’s terminal modes.  */
	tcgetattr (shell_terminal, &j->tmodes);
	tcsetattr (shell_terminal, TCSADRAIN, &shell_tmodes);
}
