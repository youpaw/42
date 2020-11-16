/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "jobs.h"

static void	set_handlers(void (*sig_handler)(int arg),
							void (*sigint_handler)(int arg))
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sig_handler);
	signal(SIGTSTP, sig_handler);
	signal(SIGTTIN, sig_handler);
	signal(SIGTTOU, sig_handler);
}

void		ignore_job_and_interactive_signals(void)
{
	set_handlers(SIG_IGN, SIG_IGN);
}

void		restore_job_and_interactive_signals(void)
{
	set_handlers(SIG_DFL, SIG_DFL);
}
