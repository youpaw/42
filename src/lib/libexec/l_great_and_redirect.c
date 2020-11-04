//
// Created by Fidelia Mallister on 11/4/20.
//

#include "exec.h"
#include <fcntl.h>
#include <unistd.h>

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

static int		minus(t_process *process, int from)
{
	if (from == STDOUT_FILENO)
		close(process->stdout);
	else if (from == STDERR_FILENO)
		close(process->stderr);
	else if (from == STDIN_FILENO)
		close(process->stdin);
	return (0);
}

int 			l_great_and_redirect(t_ast *leafs, t_process *process) // c
{
	int from;
	int to;

	from = left_side(leafs, 1);
	to = right_side(leafs, O_RDWR | O_CREAT | O_TRUNC, 1, 1);
	if (to == -2)
		return (minus(process, from));
	if (to == -1)
		return (1);
	if (to == from)
		return (0); // is it really 0?
	if (is_valid_number(leafs->left->left->token->raw) &&
	!is_standard_io(to) && !is_minus(leafs))
	{
		close(to);
		return (1); // msg_error "42sh: %to: Bad descriptor
	}
	if (STDOUT_FILENO == from)
		from_stdout(process, to);
	else if (STDERR_FILENO == from)
		from_stderr(process, to);
	else if (STDIN_FILENO == from)
		from_stdin(process, to);
	return (0);
}
