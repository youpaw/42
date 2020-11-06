//
// Created by Fidelia Mallister on 11/4/20.
//

#include "exec.h"
#include <unistd.h>
#include <fcntl.h>
#include "cc_str.h"

static int less_and_right_side(t_ast *leafs)
{
	int to;

	to = -1;
	if (leafs->left->left->token)
	{
		if (leafs->left->left->token->raw)
		{
			if (strisnum(leafs->left->left->token->raw))
			{
				to = atoi(leafs->left->left->token->raw);
				if (!is_standard_io(to))
					return (redirect_print_error(E_BADFD, leafs->left->left->token->raw));
			}
			else if (strcmp(leafs->left->left->token->raw, "-") == 0)
				return (-2);
			else
				return redirect_print_error(E_AMBIG, leafs->left->left->token->raw);
		}
	}
	return (to);
}

int 	redirect_less_and(t_ast *leafs, t_process *process) // c
{
	int from;
	int to;

	from = redirect_parse_left_side(leafs, 0);
	to = less_and_right_side(leafs);
	if (from == to)
		return (0);
	if (to == -2)
		return (minus(process, from));
	if (!is_standard_io(from) && to != -1)
		return (0);
	if (from == STDIN_FILENO)
	{
		if (!is_standard_io(process->stdin))
			close(process->stdin);
		if (STDOUT_FILENO == to)
			process->stdin = dup(process->stdout);
		if (STDERR_FILENO == to)
			process->stdin = dup(process->stderr);
	}
	else if (from == STDERR_FILENO)
	{
		if (!is_standard_io(process->stderr))
			close(process->stderr);
		if (STDOUT_FILENO == to)
			process->stderr = dup(process->stdout);
		else if (STDIN_FILENO == to)
			process->stderr = dup(process->stdin);
	}
	else if (from == STDOUT_FILENO)
	{
		if (!is_standard_io(process->stdout))
			close(process->stdout);
		if (STDERR_FILENO == to)
			process->stdout = dup(process->stderr);
		else if(STDIN_FILENO == to)
			process->stdout = dup(process->stdin);
	}
	return (0);
}