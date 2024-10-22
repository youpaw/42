/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_display_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "cc_char.h"
#include "termcap.h"

static void	clear_second_display_input(t_inp *inp)
{
	while (inp->x_pos != inp->l_len[inp->y_pos])
		handle_del(inp);
	while (inp->x_pos - get_prompt_len(inp->y_pos))
		handle_backspace(inp);
	handle_shift_up(inp);
}

static void	clear_first_display_input(t_inp *inp)
{
	while (inp->x_pos != inp->l_len[inp->y_pos])
		handle_del(inp);
	while (inp->x_pos - get_prompt_len(inp->y_pos))
		handle_backspace(inp);
}

void		clear_display_input(t_inp *inp)
{
	size_t prev_lines_count;

	put_cursor_to_the_end(inp);
	prev_lines_count = inp->y_pos;
	while (inp->y_pos)
		clear_second_display_input(inp);
	clear_first_display_input(inp);
	tputs(tgetstr("sc", NULL), 1, putchar);
	while (prev_lines_count-- != 0)
	{
		tputs(tgetstr("do", NULL), 1, putchar);
		tputs(tgetstr("cr", NULL), 1, putchar);
		tputs(tgetstr("cd", NULL), 1, putchar);
	}
	tputs(tgetstr("rc", NULL), 1, putchar);
}
