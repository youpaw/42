/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_symdol_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "readline.h"
#include "cc_char.h"
#include "cc_str.h"

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
