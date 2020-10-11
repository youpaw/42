//
// Created by Azzak Omega on 10/8/20.
//

#include "jobs.h"
#include <signal.h>
#include "cc_str.h"

/* Put a job in the background.  If the cont argument is true, send
   the process group a SIGCONT signal to wake it up.  */

void	put_job_in_background (t_job *j, int cont)
{
	/* Send the job a continue signal, if necessary.  */
	if (cont)
		if (kill(-j->pgid, SIGCONT) < 0)
			fdputendl("kill (SIGCONT)", 2);
}