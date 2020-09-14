//
// Created by Azzak Omega on 9/14/20.
//
#include "env.h"
#include "cc_str.h"
#include "error.h"

static int	print_error(const char *arg)
{
	const char 	*args[2];

	args[0] = "unset";
	args[1] = arg;
	error_print(E_INVIDENT, args);
	return (1);
}

int			unset(const char **args)
{
	int	error;

	error = 0;
	if (args)
		while (*args)
		{
			if (get_valid_name_length_no_check(*args) == strlen(*args))
			{
				env_remove_from(g_env, *args);
				env_remove_from(g_inter_env, *args);
			}
			else
				error += print_error(*args);
			args++;
		}
	return (error ? 1 : 0);
}
