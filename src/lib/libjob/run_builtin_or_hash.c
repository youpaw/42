//
// Created by Azzak Omega on 11/7/20.
//

#include "jobs.h"
#include "cc_str.h"
#include "hash.h"
#include <unistd.h>

static void backup_stdio(int stdio[3])
{
	stdio[0] = dup(STDIN_FILENO);
	stdio[1] = dup(STDOUT_FILENO);
	stdio[2] = dup(STDERR_FILENO);
}

static void restore_stdio(int stdio[3])
{
	dup2(stdio[0], STDIN_FILENO);
	dup2(stdio[1], STDOUT_FILENO);
	dup2(stdio[2], STDERR_FILENO);
}


static int		exec_or_hash(t_process *process)
{
	int		error;
	int		index;
	int		stdio[3];
	const char **argv = (const char **)process->argv;

	if ((index = get_builtin_index(argv[0])) != -1)
	{
		backup_stdio(stdio);
		if (!(error = set_redirects(process)))
			error = exec_builtin_by_index(argv, index);
		restore_stdio(stdio);
		return (error);
	}
	hash_get_path(argv[0]);
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
	return_value = exec_or_hash(process);
	if (return_value >= 0)
		process->completed = 1;
	free(process->argv);
	process->argv = NULL;
	strarr_del(process->env);
	free(process->env);
	process->env = NULL;
	return (return_value);
}
