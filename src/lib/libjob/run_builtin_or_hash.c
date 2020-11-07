//
// Created by Azzak Omega on 11/7/20.
//

#include "jobs.h"
#include "cc_str.h"
#include "hash.h"

static int		exec_or_hash(const char **argv)
{
	int		index;

	if ((index = get_builtin_index(argv[0])) != -1)
		return (exec_builtin_by_index(argv, index));
	else if (hash_get_path(argv[0]))
		return (-1);
	return (-1);
}

/*
**	Creates a temporary argv and checks if argv[0] is a builtin.
**	If argv[0] contains a '/'.
**	If argv[0] is a builtin.
**	If argv[0] is in hashmap, adds a hit tag to it, but does not execute.
**	If argv[0] is not in hashmap, add it to hashmap and add a hit to it but
**	does not execute it.
**	If argv[0] is a builtin:
**			- if it got executed, returns 0.
**			- if there was an error returns error number
**	Else (argv[0] is NOT a builtin) returns -1.
**	If execution should stop, returns -2
**
**	If fake_argv() found no real argv:
**	apply the assignation table to shell_vars (and env if 'exported')
*/

int		run_builtin_or_hash(t_process *process)
{
	int						return_value;

	if (process_init(process))
		return (1);
	return_value = exec_or_hash((const char **)process->argv);
	if (return_value >= 0)
		process->completed = 1;
	free(process->argv);
	process->argv = NULL;
	strarr_del(process->env);
	free(process->env);
	process->env = NULL;
	return (return_value);
}
