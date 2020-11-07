//
// Created by youpaw on 10/11/20.
//

#include "jobs.h"
#include "cc_str.h"
#include "hash.h"
#include <signal.h>
#include <unistd.h>

static void	set_pipes(t_process *p)
{
	if (prepare_redirect(p->ast, p))
		exit(1);
	if (p->stdin != STDIN_FILENO)
	{
		dup2 (p->stdin, STDIN_FILENO);
		close (p->stdin);
	}
	if (p->stdout != STDOUT_FILENO)
	{
		dup2 (p->stdout, STDOUT_FILENO);
		close (p->stdout);
	}
	if (p->stderr != STDERR_FILENO)
	{
		dup2 (p->stderr, STDERR_FILENO);
		close (p->stderr);
	}
}

void	launch_process(t_process *p, pid_t pgid, int is_foreground)
{
	pid_t		pid;
	const char	*path;
	int 		index;

	g_has_job_control = 0;
	if (g_is_interactive)
	{
		pid = getpid();
		if (pgid == 0)
			pgid = pid;
		setpgid(pid, pgid);
		if (is_foreground)
			tcsetpgrp (g_terminal, pgid);
	}
	set_pipes(p);
	if ((index = get_builtin_index(p->argv[0])) != -1)
		exit(exec_builtin_by_index((const char **)p->argv, index));
	if (strispath(p->argv[0]))
		path = p->argv[0];
	else
		path = hash_get_path(p->argv[0]);
	if (path)
		execve(path, p->argv, p->env);
	error_print(E_NOCMD, (const char **)p->argv);
	exit(127);
}