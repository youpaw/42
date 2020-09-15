/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_charecters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:34:59 by mgena             #+#    #+#             */
/*   Updated: 2020/08/26 15:42:11 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include "readline.h"
#include "cc_mem.h"
#include "cc_char.h"

int			handle_del(t_input *inp)
{
	unsigned char ch[5];
	int len;

	if (inp->cursor_x_position != inp->line_len[inp->cursor_y_position])
	{
		bzero(ch, 5);
		vec_get_at(ch, inp->line[inp->cursor_y_position], inp->cursor_x_position);
		len = get_displayed_symbol_len(ch);
		while (len-- != 0)
			tputs(tgetstr("dc", NULL), 1, &putchar);
		vec_rm_at(inp->line[inp->cursor_y_position], inp->cursor_x_position);
		inp->len--;
		inp->line_len[inp->cursor_y_position]--;
		check_input(inp);
	}
	else
		putchar('\7');
	return 0;
}