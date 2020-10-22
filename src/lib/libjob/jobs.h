//
// Created by Azzak Omega on 9/22/20.
//

#ifndef JOBS_H
# define JOBS_H
#include <termios.h>
#include <stddef.h>
#include "lexer.h"
#define N_JOB_BUILTINS 4

extern pid_t			g_pgid;
extern struct termios	g_tmodes;
extern int				g_terminal;
extern int				g_is_interactive;

/* A process is a single process.  */
typedef struct s_process
{
	struct s_process *next;       /* next process in pipeline */
	char **argv;                /* for exec */
	char **env;
	pid_t pid;                  /* process ID */
	char completed;             /* true if process has completed */
	char stopped;               /* true if process has stopped */
	int status;                 /* reported status value */
	int stdin;
	int	stdout;
	int	stderr;  /* standard i/o channels */
} t_process;

/* A job is a pipeline of processes.  */
typedef struct s_job
{
	struct s_job *next;           /* next active job */
	char *command;              /* command line, used for messages */
	t_process *first_process;     /* list of processes in this job */
	pid_t pgid;                 /* process group ID */
	int		index;				/* job index in list */
	char notified;              /* true if user told about stopped job */
	struct termios tmodes;      /* saved terminal modes */
	t_token 		*sequence;
} t_job;


/* The active jobs are linked into a list.  This is its head.   */
extern	t_job	*g_first_job;
extern	t_vec	*g_job_queue;




/* Find the active job with the indicated pgid.  */
t_job	*find_job (pid_t pgid);
t_job	*find_job_by_index(int index);

/* Return true if all processes in the job have stopped or completed.  */
int	job_is_stopped (t_job *j);

/* Return true if all processes in the job have completed.  */
int	job_is_completed (t_job *j);

void	jobs_init(void);
t_job	*job_new(void);
int		push_job(t_job *job);
int		del_job_by_pid(size_t pid);
void	del_process(t_process *p);
void	launch_job(t_job *job, int foreground);
void	launch_process (t_process *p, pid_t pgid, int foreground);

t_process	*process_new(void);
void	print_process_stats(const char *str);
void	put_job_in_foreground (t_job *j, int cont);
void	put_job_in_background (t_job *j, int cont);
int		mark_process_status (pid_t pid, int status);
void	update_status(void);
void	wait_for_job(t_job *j);
void	format_job_info(t_job *j, const char *status);
void	do_job_notification(void);
void	continue_job(t_job *j, int foreground);
void	mark_job_as_running(t_job *j);

void	set_dfl_handlers(void);
void	set_ignore_handlers(void);
void	set_print_child_handlers(void);
void	set_print_main_handlers(void);

/*
** Job builtins
*/

int 	run_job_builtin(const char **av, int is_foreground);
int 	sh_exit(const char **av);
int		jobs(const char **av);
int		fg(const char **av);
int		bg(const char **av);

/*
** Job queue
*/

int		get_new_job_index(void);

void	queue_print(void);
void	queue_push_back(int index);
void	queue_remove(int index);
void	queue_move_back(int index);
int 	queue_get_current(void);
int 	queue_get_last(void);

#endif
