//
// Created by Azzak Omega on 10/21/20.
//

#include "jobs.h"
#include "cc_str.h"
#include "env.h"

static	int get_builtin(const char *name)
{
	int		i;
	static const char *builtins_names[N_JOB_BUILTINS] = {
			"exit", "jobs", "fg", "bg"};
	i = 0;
	while (i < N_JOB_BUILTINS)
	{
		if (!strcmp(name, builtins_names[i]))
			return (i);
		i++;
	}
	return (-1);
}

int run_job_builtin(const char **av)
{
	int 	i;
	static int (*builtins_funcs[N_JOB_BUILTINS])(const char **) = {
			exit_builtin, jobs, fg_builtin, bg_builtin};
	if ((i = get_builtin(av[0])) == -1)
		return (1);
	g_exit_code = builtins_funcs[i](av);
	return (0);
}
