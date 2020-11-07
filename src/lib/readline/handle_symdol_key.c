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
#include "unistd.h"
#include <termcap.h>
#include "cc_char.h"
#include <sys/ioctl.h>


int handle_symbol_key(t_input *inp, char *key)
{
	if (!isprint(*key) && *key != '\n')
		return (0);
	write(STDOUT_FILENO, key, 4);
	if (vec_push_at(inp->line[inp->cursor_y_position], key, inp->cursor_x_position))
		return (1);
	inp->cursor_x_position++;
	inp->line_len[inp->cursor_y_position]++;
	inp->len++;
	redraw_input_adding(inp);
	if (*key == '\n')
		return (1);
	return (0);
}

