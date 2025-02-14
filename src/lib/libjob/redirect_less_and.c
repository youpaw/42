/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_less_and.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

static void		from_stdin(t_process *process, int from, int to)
{
	if (from == STDIN_FILENO)
	{
		if (!is_standard_io(process->stdin))
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
		if (!is_standard_io(process->stderr))
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
		if (!is_standard_io(process->stdout))
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
