/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "cc_str.h"
#include "cc_char.h"
#include <termcap.h>

void	reload_input(t_inp *inp, char *str)
{
	char *tmp;

	tmp = inp->hist_storage;
	clear_display_input(inp);
	del_input(inp);
	*inp = input_init(strdup(str));
	if (*str)
	{
		vec_del(&(inp->line[inp->y_pos]));
		inp->line[inp->y_pos] = NULL;
		inp->y_pos--;
		inp->x_pos = inp->l_len[inp->y_pos];
		redraw_input(*inp, str);
	}
	else
	{
		tputs(tgetstr("cr", NULL), 1, putchar);
		tputs(tgetstr("ce", NULL), 1, putchar);
		print_prompt(inp);
	}
	inp->hist_storage = tmp;
	free(str);
}
