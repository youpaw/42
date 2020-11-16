/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include "cc_str.h"
#include <stdlib.h>
#include "jobs.h"

pid_t			g_pgid;
struct termios	g_tmodes;
int				g_terminal;
int				g_is_interactive;
int				g_has_job_control;
int				g_can_exit;
t_job			*g_first_job = NULL;
t_vec			*g_job_queue = NULL;

void	jobs_init(void)
{
	g_terminal = STDIN_FILENO;
	g_is_interactive = isatty(g_terminal);
	g_has_job_control = 0;
	g_can_exit = 0;
	if (g_is_interactive)
	{
		g_has_job_control = 1;
		g_job_queue = vec_new(10, sizeof(int), NULL);
		while (tcgetpgrp(g_terminal) != (g_pgid = getpgrp()))
			kill(-g_pgid, SIGTTIN);
		ignore_job_and_interactive_signals();
		g_pgid = getpid();
		if (setpgid(g_pgid, g_pgid) < 0)
		{
			fdputendl("Failed to put the shell in its own process group",
						STDERR_FILENO);
			exit(1);
		}
		tcsetpgrp(g_terminal, g_pgid);
		tcgetattr(g_terminal, &g_tmodes);
	}
}
