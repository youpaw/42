//
// Created by youpaw on 10/11/20.
//

#include "jobs.h"
#include "cc_str.h"
#include "hash.h"
#include "env.h"
#include "builtins.h"
#include <signal.h>
#include <unistd.h>


#include "cc_num.h"
#include "cc_str.h"

static int	is_path(const char *str)
{
	if (*str == '/' || !strncmp(str, "./", 2) || !strncmp(str, "../", 3))
		return (1);
	return (0);
}

static void	set_pipes(t_process *p)
{
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
	pid_t pid;
	const char	*path;

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
	if (!run_builtin((const char **)p->argv) ||
			!run_job_builtin((const char **) p->argv))
		exit(g_exit_code);
	if (is_path(p->argv[0]))
		path = p->argv[0];
	else
		path = hash_get_path(p->argv[0]);
	if (path)
		execve(path, p->argv, p->env);
	error_print(E_NOCMD, (const char **)p->argv);
	exit(127);
}