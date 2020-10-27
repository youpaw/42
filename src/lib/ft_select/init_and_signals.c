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
//
//void		sighandler(int sig)
//{
//	if (sig == SIGWINCH)
//	{
//		ft_fdprintf(g_out.fd, "%s%s", g_out.move_start, g_out.clear);
//		draw_selections();
//	}
//	else if (sig == SIGINT || sig == SIGABRT || sig == SIGKILL || \
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
//		main_init();
//		init_signals();
//		draw_selections();
//	}
//}
//
//void		main_init(void)
//{
//	struct termios	tty;
//
//	g_out.fd = open(ttyname(STDIN_FILENO), O_RDWR);
//	tinit();
//	ft_putstr_fd(g_out.clear, g_out.fd);
//	ft_putstr_fd(g_out.hide_cursor, g_out.fd);
//	if (!(isatty(0)))
//	{
//		ft_printf("stdin not terminal\n");
//		exit(1);
//	}
//	tcgetattr(0, &tty);
//	g_out.savetty = tty;
//	tty.c_lflag &= ~(ICANON | ECHO);
//	tty.c_cc[VMIN] = 1;
//	tcsetattr(0, TCSAFLUSH, &tty);
//}
//
//void		return_tty(void)
//{
//	ft_fdprintf(g_out.fd, "%s%s%s", g_out.show_cursor, \
//	g_out.move_start, g_out.clear_after);
//	tcsetattr(0, TCSAFLUSH, &(g_out.savetty));
//	close(g_out.fd);
//}
