/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "cc_str.h"
#include "cc_mem.h"

void	draw_letters(t_selection *selection, int wide)
{
	if (selection->under_cursor)
		puts(g_out.reverse_video);
	puts(selection->word);
	puts(g_out.norm);
	while ((wide - selection->display_len - 1) != 0)
	{
		puts(g_out.move_right);
		wide--;
	}
}

void	draw_word(t_selection *selection, int *cur, int cn)
{
	draw_letters(selection, (get_winsize().ws_col / cn));
	selection->vert_pos = cur[0];
	selection->hor_pos = cur[1];
	(cur[1])++;
	if (cur[1] == cn)
	{
		puts(g_out.move_down);
		cur[1] = 0;
		(cur[0])++;
	}
	else
	{
		puts(" ");
	}
}

int		get_max_words_len(t_selection *selection)
{
	t_selection	*first;
	int			max_len;

	max_len = selection->display_len;
	first = selection;
	selection = selection->next;
	while (selection != first)
	{
		if (selection->display_len > (size_t)max_len)
			max_len = selection->display_len;
		selection = selection->next;
	}
	return (max_len > 2 ? max_len : 3);
}

void	draw_selections(void)
{
	t_selection *selection;
	t_selection *first;
	int			column_num;
	int			cur[2];

	selection = g_selection;
	restore_displayed(selection);
	bzero(cur, sizeof(int) * 2);
	if (!(column_num = check_winsize(get_max_words_len(selection))))
		return ;
	first = selection;
	draw_word(selection, cur, column_num);
	selection = selection->next;
	while (first != selection)
	{
		if (cur[0] == get_winsize().ws_row - 1)
			break ;
		draw_word(selection, cur, column_num);
		selection = selection->next;
	}
	g_out.cur_y_pos = cur[0];
}
