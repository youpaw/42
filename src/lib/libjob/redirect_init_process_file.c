/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_init_process_file.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include <unistd.h>

void	redirect_init_process_file(t_process *process, int from, int to)
{
	if (STDIN_FILENO == from)
	{
		if (!is_standard_io(process->stdin))
			close(process->stdin);
		process->stdin = to;
	}
	else if (STDERR_FILENO == from)
	{
		if (!is_standard_io(process->stderr))
			close(process->stderr);
		process->stderr = to;
	}
	else if (STDOUT_FILENO == from)
	{
		if (!is_standard_io(process->stdout))
			close(process->stdout);
		process->stdout = to;
	}
}
