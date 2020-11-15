/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include <sys/wait.h>

void		update_status(void)
{
	int			status;
	pid_t		pid;
	const int	opt = WUNTRACED | WNOHANG;

	pid = waitpid(WAIT_ANY, &status, opt);
	while (!mark_process_status(pid, status))
		pid = waitpid(WAIT_ANY, &status, opt);
}
