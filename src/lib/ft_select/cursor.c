/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "cc_char.h"

int		get_max_vert_elem(t_selection *selection)
{
	t_selection	*cpy;
	int			cur_hor_pos;
	int			max_pos;

	cpy = selection;
	max_pos = cpy->vert_pos;
	cur_hor_pos = cpy->hor_pos;
	selection = selection->next;
	while (selection->vert_pos == -1)
		selection = selection->next;
	while (selection != cpy)
	{
		if (selection->hor_pos == cur_hor_pos && selection->vert_pos > max_pos)
			max_pos = selection->vert_pos;
		selection = selection->next;
	}
	return (max_pos);
}

int		move_cursor_down(t_selection **selection)
{
	int			to_find_vert;
	int			to_find_hor;
	t_selection	*cpy;

	cpy = get_under_cursor(selection);
	if (cpy->vert_pos == get_max_vert_elem(cpy))
		putchar('\7');
	else
	{
		to_find_hor = cpy->hor_pos;
		to_find_vert = cpy->vert_pos + 1;
		set_cursor_on_pos(cpy, to_find_hor, to_find_vert);
	}
	return (0);
}

int		move_cursor_up(t_selection **selection)
{
	int			to_find_vert;
	int			to_find_hor;
	t_selection *cpy;

	cpy = get_under_cursor(selection);
	if (cpy->vert_pos == 0)
		putchar('\7');
	else
	{
		to_find_hor = cpy->hor_pos;
		to_find_vert = cpy->vert_pos - 1;
		set_cursor_on_pos(cpy, to_find_hor, to_find_vert);
	}
	return (0);
}
