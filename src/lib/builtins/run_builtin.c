//
// Created by Azzak Omega on 9/16/20.
//

#include "builtins.h"
#include "cc_str.h"
#include "env.h"

static	int get_builtin(const char *name)
{
	int		i;
	static const char *builtins_names[5] = {
			"exit", "set", "unset", "cd", "export"};
	i = 0;
	while (i < 5)
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
	static int (*builtins_funcs[5])(const char **) = {
			sh_exit, set, unset, cd, export};

	if ((i = get_builtin(av[0])) == -1)
		return (0);
	g_exit_code = builtins_funcs[i](av);
	return (1);
}