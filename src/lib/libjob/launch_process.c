//
// Created by youpaw on 10/11/20.
//

#include "jobs.h"
#include "cc_str.h"
#include "hash.h"
#include <signal.h>
#include <unistd.h>

static void		set_process_group(int *pgid, int is_foreground)
{
	pid_t		pid;

	pid = getpid();
	if (*pgid == 0)
		*pgid = pid;
	setpgid(pid, *pgid);
	if (is_foreground)
	{
		if (tcsetpgrp(g_terminal, *pgid) < 0)
		{
			fdputendl("Terminal failed to return", 2);
			exit(1);
		}
	}
}

void			launch_process(t_process *p, pid_t pgid, int is_foreground)
{
	const char	*path;
	int			index;

	g_has_job_control = 0;
	restore_job_and_interactive_signals();
	putendl("before restore");
	if (g_is_interactive)
		set_process_group(&pgid, is_foreground);
	putendl("after restore");
	if (process_init(p) || set_redirects(p))
		exit(1);
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
