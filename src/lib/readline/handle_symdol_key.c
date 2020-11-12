/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:13:55 by mgena             #+#    #+#             */
/*   Updated: 2020/08/26 19:19:08 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "cc_char.h"
#include "cc_str.h"
#include "cc_num.h"
#include <sys/ioctl.h>
#include <termcap.h>

int		handle_symbol_key(t_inp *inp, char *key)
{
	struct winsize ws;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	if (*key > 0 && *key < 32 && *key != '\n' && *key != '\4')
		return (0);
	if (*key == '\n')
		put_cursor_to_the_end(inp);
	write(STDOUT_FILENO, key, 4);
	vec_push_at(inp->line[inp->y_pos], key, inp->x_pos);
	inp->x_pos++;
	inp->l_len[inp->y_pos]++;
	inp->len++;
	if (!(inp->x_pos % ws.ws_col) && inp->x_pos)
	{
		tputs(tgetstr("do", NULL), 1, &putchar);
		tputs(tgetstr("cr", NULL), 1, &putchar);
	}
	redraw_input_readline(inp);
	if (*key == '\n' || *key == '\4')
		return (1);
	return (0);
}
