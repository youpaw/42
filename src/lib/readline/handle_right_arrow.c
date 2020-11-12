/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:01:01 by mgena             #+#    #+#             */
/*   Updated: 2020/08/22 17:39:07 by mgena            ###   ########.fr       */
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
		if (!(inp->x_pos % (ws.ws_col - 1)) && inp->x_pos)
		{
			tputs(tgetstr("do", NULL), 1, &putchar);
			tputs(tgetstr("cr", NULL), 1, &putchar);
			putchar('\7');
		}
		else
			tputs(tgetstr("nd", NULL), 1, &putchar);
		inp->x_pos++;
	}
	else
		putchar('\7');
	return (0);
}
