/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_job_in_foreground.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include <signal.h>
#include <unistd.h>
#include "cc_str.h"

int		put_job_in_foreground(t_job *j, int cont)
{
	int		return_value;

	tcsetpgrp(g_terminal, j->pgid);
	if (cont)
	{
		putendl(j->command);
		tcsetattr(g_terminal, TCSADRAIN, &j->tmodes);
		if (kill(-j->pgid, SIGCONT) < 0)
			fdputendl("kill (SIGCONT)", 2);
	}
	return_value = wait_for_job(j, WUNTRACED);
	if (tcsetpgrp(g_terminal, g_pgid) < 0)
	{
		fdputendl("Terminal failed to return", 2);
		exit(1);
	}
	tcgetattr(g_terminal, &j->tmodes);
	tcsetattr(g_terminal, TCSADRAIN, &g_tmodes);
	if ((WIFSIGNALED(return_value) && WTERMSIG(return_value) == SIGINT) ||
			WIFSTOPPED(return_value))
		fdputendl("", 2);
	return (return_value);
}
