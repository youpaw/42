/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_close_stdio.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include <unistd.h>

int		redirect_close_stdio(t_process *process, int from)
{
	if (from == STDOUT_FILENO)
		close(process->stdout);
	else if (from == STDERR_FILENO)
		close(process->stderr);
	else if (from == STDIN_FILENO)
		close(process->stdin);
	return (0);
}
