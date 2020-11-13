//
// Created by Azzak Omega on 10/8/20.
//

#include <signal.h>
#include "jobs.h"
#include "cc_str.h"

void	put_job_in_background(t_job *j, int cont)
{
	if (cont)
		if (kill(-j->pgid, SIGCONT) < 0)
			fdputendl("kill (SIGCONT)", 2);
}
