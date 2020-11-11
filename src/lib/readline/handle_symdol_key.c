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

int handle_symbol_key(t_inp *inp, char *key)
{
	struct winsize ws;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	if (*key > 0 && *key < 32 && *key != '\n')
		return (0);
	if (*key == '\n')
		put_cursor_to_the_end(inp);
	write(STDOUT_FILENO, key, 4);
	if (vec_push_at(inp->line[inp->cursor_y_position], key, inp->cursor_x_position))
		return (1);
	inp->cursor_x_position++;
	inp->line_len[inp->cursor_y_position]++;
	inp->len++;
	if (!(inp->cursor_x_position % ws.ws_col) && inp->cursor_x_position)
	{
		tputs(tgetstr("do", NULL), 1, &putchar);
		tputs(tgetstr("cr", NULL), 1, &putchar);
	}
	redraw_input_readline(inp);
	if (*key == '\n')
		return (1);
	return (0);
}

