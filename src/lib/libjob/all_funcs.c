//
// Created by Azzak Omega on 10/8/20.
//
#include "jobs.h"
#include <stddef.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "cc_str.h"

/* Find the active job with the indicated pgid.  */
t_job	*find_job (pid_t pgid)
{
	t_job *j;

	for (j = g_first_job; j; j = j->next)
		if (j->pgid == pgid)
			return j;
	return NULL;
}

/* Return true if all processes in the job have stopped or completed.  */
int	job_is_stopped (t_job *j)
{
	t_process *p;

	for (p = j->first_process; p; p = p->next)
		if (!p->completed && !p->stopped)
			return 0;
	return 1;
}

/* Return true if all processes in the job have completed.  */
int	job_is_completed (t_job *j)
{
	t_process *p;

	for (p = j->first_process; p; p = p->next)
		if (!p->completed)
			return 0;
	return 1;
}

void	launch_process (t_process *p, pid_t pgid,
						int infile, int outfile, int errfile,
						int foreground)
{
	pid_t pid;

	if (g_is_interactive)
	{
		/* Put the process into the process group and give the process group
		   the terminal, if appropriate.
		   This has to be done both by the shell and in the individual
		   child processes because of potential race conditions.  */
		pid = getpid();
		if (pgid == 0)
			pgid = pid;
		setpgid(pid, pgid);
		if (foreground)
			tcsetpgrp (g_terminal, pgid);

		/* Set the handling for job control signals back to the default.  */
		signal (SIGINT, SIG_DFL);
		signal (SIGQUIT, SIG_DFL);
		signal (SIGTSTP, SIG_DFL);
		signal (SIGTTIN, SIG_DFL);
		signal (SIGTTOU, SIG_DFL);
		signal (SIGCHLD, SIG_DFL);
	}

	/* Set the standard input/output channels of the new process.  */
	if (infile != STDIN_FILENO)
	{
		dup2 (infile, STDIN_FILENO);
		close (infile);
	}
	if (outfile != STDOUT_FILENO)
	{
		dup2 (outfile, STDOUT_FILENO);
		close (outfile);
	}
	if (errfile != STDERR_FILENO)
	{
		dup2 (errfile, STDERR_FILENO);
		close (errfile);
	}

	/* Exec the new process.  Make sure we exit.  */
	execvp(p->argv[0], p->argv);
	fdputendl("execvp error", 2);
	exit(1);
}

void	launch_job(t_job *j, int foreground)
{
	t_process *p;
	pid_t pid;
	int mypipe[2], infile, outfile;

	infile = j->stdin;
	for (p = j->first_process; p; p = p->next)
	{
		/* Set up pipes, if necessary.  */
		if (p->next)
		{
			if (pipe(mypipe) < 0)
			{
				fdputendl("pipe error", 2);
				exit(1);
			}
			outfile = mypipe[1];
		}
		else
			outfile = j->stdout;

		/* Fork the child processes.  */
		pid = fork ();
		if (pid == 0)
			/* This is the child process.  */
			launch_process (p, j->pgid, infile,
							outfile, j->stderr, foreground);
		else if (pid < 0)
		{
			/* The fork failed.  */
			fdputendl("fork error", 2);
			exit (1);
		}
		else
		{
			/* This is the parent process.  */
			p->pid = pid;
			if (g_is_interactive)
			{
				if (!j->pgid)
					j->pgid = pid;
				setpgid (pid, j->pgid);
			}
		}

		/* Clean up after pipes.  */
		if (infile != j->stdin)
			close (infile);
		if (outfile != j->stdout)
			close (outfile);
		infile = mypipe[0];
	}
	format_job_info(j, "launched");
	if (!g_is_interactive)
		wait_for_job(j);
	else if (foreground)
		put_job_in_foreground(j, 0);
	else
		put_job_in_background(j, 0);
}
