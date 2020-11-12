//
// Created by youpaw on 10/11/20.
//

#include "jobs.h"
#include "cc_str.h"
#include "hash.h"
#include "env.h"
#include <signal.h>
#include <unistd.h>

static void	set_process_group(int *pgid, int is_foreground)
{
	pid_t		pid;

	pid = getpid();
	if (*pgid == 0)
		*pgid = pid;
	setpgid(pid, *pgid);

	if (is_foreground)
	{
		if( tcsetpgrp(g_terminal, *pgid) < 0)
		{
			fdputendl("Terminal failed to return", 2);
			exit(1);
		}
	}
}

static void		get_exec_env(t_process *p)
{

	prepare_exec_env(p->ast->left);
	p->env = exec_env_2array();
	exec_env_del();
}

static void 	destruct_process(t_process *p)
{
	free(p->argv);
	strarr_del(p->env);
	free(p->env);
}

static	void 	try_execv(const char *path, t_process *p)
{
	int 		err_code;
	const char	*err_args[2];

	err_args[1] = "";
	if (access(path, F_OK) == 0)
	{
		if (access(path, X_OK) == 0)
			execve(path, p->argv, p->env);
		error_print(E_ACCES, (const char **) p->argv);
		err_code = 126;
	} else
	{
		err_args[0] = path;
		error_print(E_NOENT, err_args);
		err_code = 127;
	}
	destruct_process(p);
	exit(err_code);
}

void	launch_process(t_process *p, pid_t pgid, int is_foreground)
{
	const char	*path;
	int 		err_code;

	g_has_job_control = 0;
	restore_job_and_interactive_signals();
	if (g_is_interactive)
		set_process_group(&pgid, is_foreground);
	if ((err_code = process_init(p)))
		free(p->argv);
	if (err_code || set_redirects(p))
		exit(1);
	if (!p->argv)
		exit(0);
	if ((err_code = run_builtin(p)) >= 0)
		exit(err_code);
	if (strispath(p->argv[0]))
		path = p->argv[0];
	else
		path = hash_get_path(p->argv[0]);
	get_exec_env(p);
	if (path)
		try_execv(path, p);
	error_print(E_NOCMD, (const char **)p->argv);
	destruct_process(p);
	exit(127);
}