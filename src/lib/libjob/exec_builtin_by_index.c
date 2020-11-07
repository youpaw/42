//
// Created by Azzak Omega on 11/7/20.
//

#include "builtins.h"
#include "jobs.h"

int 	exec_builtin_by_index(const char **av, int index)
{
	static int (*builtins_funcs[N_BUILTINS])(const char **) = {
			exit_builtin, set, unset, cd, export, hash, echo,
			alias, unalias, // replace set and unset to alias and unalias
			jobs, fg_builtin, bg_builtin};

	if (index)
		g_can_exit = 0;
	return (builtins_funcs[index](av));
}
