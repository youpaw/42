//
// Created by Azzak Omega on 10/8/20.
//

#include <signal.h>
#include "jobs.h"
#include "cc_str.h"

/* Put a job in the background.  If the cont argument is true, send
   the process group a SIGCONT signal to wake it up.  */

void	put_job_in_background (t_job *j, int cont)
{
	if (cont)
		if (kill(-j->pgid, SIGCONT) < 0)
			fdputendl("kill (SIGCONT)", 2);
}