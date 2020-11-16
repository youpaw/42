/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_right_arrow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <termcap.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "cc_mem.h"
#include "cc_char.h"

int		handle_right_arrow(t_inp *inp)
{
	struct winsize ws;

	if (inp->x_pos != inp->l_len[inp->y_pos])
	{
		ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
		inp->x_pos++;
		if (!(inp->x_pos % ws.ws_col) && inp->x_pos)
		{
			tputs(tgetstr("do", NULL), 1, &putchar);
			tputs(tgetstr("cr", NULL), 1, &putchar);
			putchar('\7');
		}
		else
			tputs(tgetstr("nd", NULL), 1, &putchar);
	}
	else
		putchar('\7');
	return (0);
}
