//
// Created by Azzak Omega on 9/22/20.
//

#ifndef JOBS_H
# define JOBS_H
#include "cc_vec.h"
#include <unistd.h>

typedef struct	s_jobs
{
	t_vec		*data;
	size_t		last_job_index;
	pid_t		root_pid;
}				t_jobs;

typedef struct	s_job
{
	size_t		id;
	size_t		pid;
	size_t		gpid;
}				t_job;

extern t_jobs	g_jobs;

/*
** Process management section
*/

int		is_root_process(void);
void	print_process_stats(const char *str);

/*
** Job management section
*/

void	jobs_init(void);
void	print_jobs(void);
void	add_job_to_list(size_t pid, size_t gpid);
int		remove_job_by_index(size_t index);
int		remove_job_by_pid(size_t pid);
void	check_jobs(void);

/*
** Signals section
*/

void	set_dfl_handlers(void);
void	set_main_handlers(void);
void	set_fork_handlers(void);

#endif //JOBS_H
