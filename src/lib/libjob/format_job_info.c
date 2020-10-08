//
// Created by Azzak Omega on 10/8/20.
//
#include "jobs.h"
#include <stdio.h>

/* Format information about job status for the user to look at.  */

void	format_job_info(job *j, const char *status)
{
	fprintf (stderr, "%ld (%s): %s\n", (long)j->pgid, status, j->command);
}
