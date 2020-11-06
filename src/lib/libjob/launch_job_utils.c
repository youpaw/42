//
// Created by Azzak Omega on 11/6/20.
//

#include "jobs.h"
#include "cc_str.h"
#include <unistd.h>

static void	clean_fds_after_pipes(int *in_out_fds, int *pipe_fds)
{
	if (in_out_fds[0] != STDIN_FILENO)
		close(in_out_fds[0]);
	if (in_out_fds[1] != STDOUT_FILENO)
		close(in_out_fds[1]);
	in_out_fds[0] = pipe_fds[0];
}

static void	set_pipe_fds(t_process *process, int *in_out_fds, int *pipe_fds)
{
	if (process->next)
	{
		if (pipe(pipe_fds) < 0)
		{
			fdputendl("pipe error", 2);
			exit_shell(1);
		}
		in_out_fds[1] = pipe_fds[1];
	}
	else
		in_out_fds[1] = STDOUT_FILENO;
	if (process->stdin == STDIN_FILENO)
		process->stdin = in_out_fds[0];
	if (process->stdout == STDOUT_FILENO)
		process->stdout = in_out_fds[1];
}

static void	continue_in_parent(t_job *job, t_process *process, pid_t pid)
{
	process->pid = pid;
	if (g_is_interactive)
	{
		if (!job->pgid)
			job->pgid = pid;
		setpgid(pid, job->pgid);
	}
}

void fork_and_launch_process(t_job *job, int is_foreground)
{
	pid_t		pid;
	t_process	*p;
	int			in_out_fds[2];
	int 		pipe_fds[2];

	in_out_fds[0] = STDIN_FILENO; // is redirect here?
	p = job->first_process;
	while (p)
	{
		set_pipe_fds(p, in_out_fds, pipe_fds);
		pid = fork();
		if (pid == 0)
		{
			restore_job_and_interactive_signals();
			if (in_out_fds[0] != pipe_fds[0])
				close(pipe_fds[0]);
			launch_process(p, job->pgid, is_foreground);
		}
		else if (pid < 0)
		{
			fdputendl("fork failed", 2);
			exit_shell(1);
		}
		else
			continue_in_parent(job, p, pid);
		clean_fds_after_pipes(in_out_fds, pipe_fds);
		p = p->next;
	}
}
