//
// Created by Azzak Omega on 9/22/20.
//

#ifndef JOBS_H
# define JOBS_H
#include "cc_vec.h"


typedef struct	s_jobs
{
	t_vec		*data;
	size_t		index;
}				t_jobs;

extern t_jobs	g_jobs;

typedef struct	s_job
{
	size_t		job_pid;
	size_t		group_pid;
	int 		status;
}				t_job;

void	print_process_stats(void);
void	jobs_init(void);
void	print_jobs(void);
void	jobs_add(size_t pid, size_t gpid);

#endif //JOBS_H
