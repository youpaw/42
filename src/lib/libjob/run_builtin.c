//
// Created by Azzak Omega on 9/16/20.
//

#include "builtins.h"
#include "cc_str.h"
#include "env.h"
#include "jobs.h"

static	int get_builtin(const char *name)
{
	int		i;
	static const char *builtins_names[N_BUILTINS] = {
			"set", "unset", "cd", "export", "hash", "echo"};
	i = 0;
	while (i < N_BUILTINS)
	{
		if (!strcmp(name, builtins_names[i]))
			return (i);
		i++;
	}
	return (-1);
}

int 	run_builtin(const char **av)
{
	int 	i;
	static int (*builtins_funcs[N_BUILTINS])(const char **) = {
			set, unset, cd, export, hash, echo};
	if ((i = get_builtin(av[0])) == -1)
		return (1);
	g_can_exit = 0;
	g_exit_code = builtins_funcs[i](av);
	return (0);
}
