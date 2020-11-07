//
// Created by Azzak Omega on 11/7/20.
//

#include "jobs.h"
#include "cc_str.h"
#include "hash.h"

/*
static char		**fake_argv(t_token *token_head, t_vars *vars)
{
	t_token					*cpy;
	char					**argv;

	argv = NULL;
	vars->verbose = 0;
	cpy = copy_tokens(token_head);
	parse_expands(cpy, vars);
	parse_redirections(cpy, -1);
	parse_assignation(cpy, vars);
	get_argv_from_token_lst(cpy, &argv);
	free_token_list(cpy);
	vars->verbose = 1;
	return (argv);
}
 */

static int		exec_or_hash(const char **argv)
{
	int		index;

	if ((index = get_builtin_index(argv[0])) != -1)
		return (exec_builtin_by_index(argv, index));
	else if (strchr(argv[0], '/') || hash_get_path(argv[0]) )
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

//	if (!(argv = fake_argv(token_head, vars)) || !argv[0])
//	{
//		if (parse_expands(token_head, vars))
//			return (-2);
//		save_reset_stdfd(1);
//		parse_redirections(token_head, 0);
//		save_reset_stdfd(0);
//		parse_assignation(token_head, vars);
//		apply_assignation(&vars->assign_tab, vars);
//		return (0);
//	}
	return_value = exec_or_hash((const char **)process->argv);
	if (return_value >= 0)
		process->completed = 1;
	return (return_value);
}
