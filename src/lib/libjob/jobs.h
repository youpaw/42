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
	size_t		id;
	size_t		pid;
	size_t		gpid;
}				t_job;

void	print_process_stats(const char *str);
void	jobs_init(void);
void	print_jobs(void);
void	jobs_add(size_t pid, size_t gpid);

/*
** Signals section
*/

void	set_dfl_handlers(void);
void	set_main_handlers(void);
void	set_fork_handlers(void);


#endif //JOBS_H
