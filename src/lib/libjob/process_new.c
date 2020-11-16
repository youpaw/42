/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "cc_mem.h"
#include <unistd.h>

t_process	*process_new(void)
{
	t_process *process;

	process = xmalloc(sizeof(t_process));
	process->next = NULL;
	process->ast = NULL;
	process->argv = NULL;
	process->env = NULL;
	process->completed = 0;
	process->stopped = 0;
	process->status = 0;
	process->stdin = STDIN_FILENO;
	process->stdout = STDOUT_FILENO;
	process->stderr = STDERR_FILENO;
	return (process);
}
