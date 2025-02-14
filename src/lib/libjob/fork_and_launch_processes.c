/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_launch_processes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (job->is_fg && tcsetpgrp(g_terminal, job->pgid) < 0)
	{
		fdputendl("Terminal failed to return", 2);
		exit(1);
	}
}

static void	set_process_io(t_process *p, const int *in_out_fds, int *pipe_fds)
{
	if (in_out_fds[0] != pipe_fds[0])
		close(pipe_fds[0]);
	p->stdin = in_out_fds[0];
	p->stdout = in_out_fds[1];
}

void		fork_and_launch_processes(t_job *job, int is_foreground)
{
	pid_t		pid;
	t_process	*p;
	int			in_out_fds[2];
	int			pipe_fds[2];

	set_default_pipe_fds(in_out_fds, pipe_fds);
	p = job->first_process;
	while (p)
	{
		set_pipe_fds(p, in_out_fds, pipe_fds);
		if (!(pid = fork()))
		{
			set_process_io(p, in_out_fds, pipe_fds);
			launch_process(p, job->pgid, is_foreground);
		}
		else if (pid < 0)
		{
			fdputendl("fork failed", 2);
			exit_shell(1);
		}
		continue_in_parent(job, p, pid);
		clean_fds_after_pipes(in_out_fds, pipe_fds);
		p = p->next;
	}
}
