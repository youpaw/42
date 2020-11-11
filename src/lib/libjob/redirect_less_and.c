//
// Created by Fidelia Mallister on 11/4/20.
//

#include "jobs.h"
#include "cc_num.h"

static void		from_stdin(t_process *process, int from, int to)
{
	if (from == STDIN_FILENO)
	{
		close(process->stdin);
		if (STDOUT_FILENO == to)
			process->stdin = dup(process->stdout);
		if (STDERR_FILENO == to)
			process->stdin = dup(process->stderr);
	}
}

static void		from_stderr(t_process *process, int from, int to)
{
	if (from == STDERR_FILENO)
	{
		close(process->stderr);
		if (STDOUT_FILENO == to)
			process->stderr = dup(process->stdout);
		else if (STDIN_FILENO == to)
			process->stderr = dup(process->stdin);
	}
}

static void		from_stdout(t_process *process, int from, int to)
{
	if (from == STDOUT_FILENO)
	{
		close(process->stdout);
		if (STDERR_FILENO == to)
			process->stdout = dup(process->stderr);
		else if (STDIN_FILENO == to)
			process->stdout = dup(process->stdin);
	}
}

static void		less_and_init_stdio(t_process *process, int from, int to)
{
	from_stdin(process, from, to);
	from_stderr(process, from, to);
	from_stdout(process, from, to);
}

int				redirect_less_and(t_ast *leafs, t_process *process)
{
	int from;
	int to;

	from = redirect_parse_left_side(leafs, 0);
	to = redirect_less_and_right_side(leafs);
	if (to == -1)
		return (-1);
	if (from == to)
		return (0);
	if (to == -2)
		return (redirect_close_stdio(process, from));
	if (!is_standard_io(from))
		return (0);
	less_and_init_stdio(process, from, to);
	return (0);
}
