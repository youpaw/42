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

int			handle_del(t_inp *inp)
{
	if (inp->x_pos != inp->l_len[inp->y_pos])
	{
		tputs(tgetstr("ce", NULL), 1, &putchar);
		vec_rm_at(inp->line[inp->y_pos], inp->x_pos);
		inp->len--;
		inp->l_len[inp->y_pos]--;
		redraw_input_readline(inp);
	}
	else
		putchar('\7');
	return 0;
}