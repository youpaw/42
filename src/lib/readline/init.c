/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:38:43 by mgena             #+#    #+#             */
/*   Updated: 2020/08/22 17:39:07 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	tinit(void)
{
	int error;

	g_out.p = g_out.strings;
	g_out.tname = getenv("TERM");
	error = tgetent(g_out.tbuf, g_out.tname);
	if (error == 0)
	{
		; //TODO "Терминал %s не описан\n" error handle
		exit(0);
	}
	else if (error == 1)
		return ;
	else
	{
		; //TODO "Different error" error handle
	}
}


void		main_init(void)
{
	struct termios	tty;

	g_out.fd = open(ttyname(STDIN_FILENO), O_RDWR);
	tinit();
	tputs(tgetstr("cl", NULL), 1, ft_put); // clear screen
	tputs(tgetstr("im", NULL), 1, ft_put); // enter 'insert on' mode
	if (!(isatty(0)))
	{
		//TODO "stdin not terminal" error handle
		exit(1);
	}
	tcgetattr(0, &tty);
	g_out.savetty = tty;
	tty.c_lflag &= ~(ICANON | ECHO);
	tty.c_cc[VMIN] = 1;
	tcsetattr(0, TCSAFLUSH, &tty);
}

void		return_tty(void)
{
	tcsetattr(0, TCSAFLUSH, &(g_out.savetty));
	tputs(tgetstr("ei", NULL), 1, ft_put); // enter 'insert off' mode
	close(g_out.fd);
}
