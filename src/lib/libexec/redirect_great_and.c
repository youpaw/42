//
// Created by Fidelia Mallister on 11/4/20.
//

#include "exec.h"
#include <fcntl.h>
#include <unistd.h>
#include "cc_str.h"

static void 	from_stdout(t_process *process, int to)
{
	if (!is_standard_io(process->stdout))
		close(process->stdout);
	if (STDERR_FILENO == to)
		process->stdout = dup(process->stderr);
	else if (STDIN_FILENO == to)
		process->stdout = dup(process->stdin);
	else
	{
		if (!is_standard_io(to))
		{
			process->stdout = to;
			if (!is_standard_io(process->stderr))
				close(process->stderr);
			process->stderr = dup(to);
		}
	}
}

static void 	from_stderr(t_process *process, int to)
{
	if (!is_standard_io(process->stderr))
		close(process->stderr);
	if (STDIN_FILENO == to)
		process->stderr = dup(process->stdin);
	else if (STDOUT_FILENO == to)
		process->stderr = dup(process->stdout);
	else
		process->stderr = to;
}

static void 	from_stdin(t_process *process, int to)
{
	if (!is_standard_io(process->stdin))
		close(process->stdin);
	if (STDOUT_FILENO == to)
		process->stdin = dup(process->stdout);
	else if (STDERR_FILENO == to)
		process->stdin = dup(process->stderr);
	else
		process->stdin = to;
}

int 			redirect_great_and(t_ast *leafs, t_process *process) // c
{
	int from;
	int to;

	from = redirect_parse_left_side(leafs, 1);
	if (STDOUT_FILENO != from && !strisnum(leafs->left->left->token->raw))
		return (redirect_print_error(E_AMBIG, leafs->left->left->token->raw));
	to = redirect_parse_right_side(leafs, O_RDWR | O_CREAT | O_TRUNC, 1, 1);
	if (to == -2)
		return (minus(process, from));
	if (to == -1)
		return (1);
	if (to == from)
		return (0); // is it really 0?
	if (strisnum(leafs->left->left->token->raw) &&
	!is_standard_io(to) && !is_minus(leafs))
	{
		close(to);
		return (redirect_print_error(E_BADFD, leafs->left->left->token->raw));
	}
	if (STDOUT_FILENO == from)
		from_stdout(process, to);
	else if (STDERR_FILENO == from)
		from_stderr(process, to);
	else if (STDIN_FILENO == from)
		from_stdin(process, to);
	return (0);
}
