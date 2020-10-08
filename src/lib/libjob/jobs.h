//
// Created by Azzak Omega on 9/22/20.
//

#ifndef JOBS_H
# define JOBS_H
#include <termios.h>
#include <stddef.h>

extern pid_t			shell_pgid;
extern struct termios	shell_tmodes;
extern int				shell_terminal;
extern int				shell_is_interactive;

/* A process is a single process.  */
typedef struct process
{
	struct process *next;       /* next process in pipeline */
	char **argv;                /* for exec */
	pid_t pid;                  /* process ID */
	char completed;             /* true if process has completed */
	char stopped;               /* true if process has stopped */
	int status;                 /* reported status value */
} process;

/* A job is a pipeline of processes.  */
typedef struct job
{
	struct job *next;           /* next active job */
	char *command;              /* command line, used for messages */
	process *first_process;     /* list of processes in this job */
	pid_t pgid;                 /* process group ID */
	char notified;              /* true if user told about stopped job */
	struct termios tmodes;      /* saved terminal modes */
	int stdin;
	int	stdout;
	int	stderr;  /* standard i/o channels */
} job;

/* The active jobs are linked into a list.  This is its head.   */
extern	job *first_job;


/* Find the active job with the indicated pgid.  */
job	*find_job (pid_t pgid);

/* Return true if all processes in the job have stopped or completed.  */
int	job_is_stopped (job *j);

/* Return true if all processes in the job have completed.  */
int	job_is_completed (job *j);

void	init_shell(void);
void	print_process_stats(const char *str);
void	put_job_in_foreground (job *j, int cont);
void	put_job_in_background (job *j, int cont);
int		mark_process_status (pid_t pid, int status);
void	update_status(void);
void	wait_for_job(job *j);
void	format_job_info(job *j, const char *status);
void	do_job_notification(void);
void	continue_job(job *j, int foreground);
void	mark_job_as_running(job *j);

void	set_dfl_handlers(void);
void	set_ignore_handlers(void);

#endif
