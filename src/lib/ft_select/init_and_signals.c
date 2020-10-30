/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_signals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:11:06 by mgena             #+#    #+#             */
/*   Updated: 2020/08/16 14:50:01 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "cc_str.h"
#include "cc_char.h"
//void		init_signals(void)
//{
//	signal(SIGINT, sighandler);
//	signal(SIGABRT, sighandler);
//	signal(SIGKILL, sighandler);
//	signal(SIGSTOP, sighandler);
//	signal(SIGQUIT, sighandler);
//	signal(SIGWINCH, sighandler);
//	signal(SIGTSTP, sighandler);
//	signal(SIGCONT, sighandler);
//}

//void		sighandler(int sig)
//{
//	if (sig == SIGWINCH)
//	{
//		ft_fdprintf(g_out.fd, "%s%s", g_out.move_start, g_out.clear);
//		draw_selections();
//	}
//	else
//	if (sig == SIGINT || sig == SIGABRT || sig == SIGKILL || \
//	sig == SIGSTOP || sig == SIGQUIT)
//		escape();
//	else if (sig == SIGTSTP)
//	{
//		return_tty();
//		signal(SIGTSTP, SIG_DFL);
//		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
//	}
//	else if (sig == SIGCONT)
//	{
//		select_init();
//		init_signals();
//		draw_selections();
//	}
//}

void		select_init(void)
{
	tinit();
	puts(g_out.hide_cursor);
}

