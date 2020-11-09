//
// Created by Azzak Omega on 11/7/20.
//

#include "jobs.h"
#include "cc_str.h"
#include "hash.h"
#include <unistd.h>

static void backup_stdio(int stdio_bck[3])
{
	stdio_bck[0] = dup(STDIN_FILENO);
	stdio_bck[1] = dup(STDOUT_FILENO);
	stdio_bck[2] = dup(STDERR_FILENO);
}

static void restore_stdio(int stdio_bck[3])
{
	dup2(stdio_bck[0], STDIN_FILENO);
	dup2(stdio_bck[1], STDOUT_FILENO);
	dup2(stdio_bck[2], STDERR_FILENO);
	close(stdio_bck[0]);
	close(stdio_bck[1]);
	close(stdio_bck[2]);
}


static int		exec_or_hash(t_process *process)
{
	int		error;
	int		index;
	int		stdio_bck[3];
	const char **argv = (const char **)process->argv;

	if ((index = get_builtin_index(argv[0])) != -1)
	{
		backup_stdio(stdio_bck);
		if (!(error = set_redirects(process)))
			error = exec_builtin_by_index(argv, index);
		restore_stdio(stdio_bck);
		return (error);
	}
	hash_get_path(argv[0]);
	return (-1);
}

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
