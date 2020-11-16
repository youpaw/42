/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
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
	return (0);
}
