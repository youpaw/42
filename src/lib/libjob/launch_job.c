//
// Created by youpaw on 10/11/20.
//

#include "jobs.h"
#include "cc_str.h"
#include <unistd.h>
#include "cc_num.h"

void	launch_job(t_job *job, int foreground)
{
	t_process *process;
	pid_t pid;
	int pfd[2];
	int infile;
	int outfile;

	infile = STDIN_FILENO;
	for (process = job->first_process; process; process = process->next)
	{
		/* Set up pipes, if necessary.  */
		if (process->next)
		{
			if (pipe(pfd) < 0)
			{
				fdputendl("pipe error", 2);
				exit(1);
			}
			outfile = pfd[1];
		}
		else
			outfile = STDOUT_FILENO;

		/* Fork the child processes.  */
		if (process->stdin == STDIN_FILENO)
			process->stdin = infile;
		if (process->stdout == STDOUT_FILENO)
			process->stdout = outfile;
		pid = fork ();
		if (pid == 0)
		{
			/* This is the child process.  */
			launch_process(process, job->pgid, foreground);
		}
		else if (pid < 0)
		{
			/* The fork failed.  */
			fdputendl("fork error", 2);
			exit (1);
		}
		else
		{
			/* This is the parent process.  */
			set_print_main_handlers();
			//set_print_child_handlers();
			process->pid = pid;
			if (g_is_interactive)
			{
				if (!job->pgid)
					job->pgid = pid;
				setpgid (pid, job->pgid);
			}
		}

		/* Clean up after pipes.  */
		if (infile != STDIN_FILENO)
			close (infile);
		if (outfile != STDOUT_FILENO)
			close (outfile);
		infile = pfd[0];
	}
	format_job_info(job, "launched");
	if (!g_is_interactive)
		wait_for_job(job);
	else if (foreground)
		put_job_in_foreground(job, 0);
	else
		put_job_in_background(job, 0);
}