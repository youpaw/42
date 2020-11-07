//
// Created by Azzak Omega on 11/7/20.
//

#include "cc_str.h"
#include "jobs.h"

int get_builtin_index(const char *name)
{
	int		i;
	static const char *builtins_names[N_BUILTINS] = {
			"exit", "set", "unset", "cd", "export", "hash",
			"echo", "alias", "unalias", "jobs", "fg", "bg"};

	i = -1;
	while (++i < N_BUILTINS)
		if (!strcmp(name, builtins_names[i]))
			return (i);
	return (-1);
}
