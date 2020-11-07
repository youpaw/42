//
// Created by Azzak Omega on 11/7/20.
//

#include "cc_str.h"
#include "cc_num.h"
#include "jobs.h"

void    print_job_pid(t_job *job)
{
	putnbr(job->pgid);
	puts("\n");
}
