/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_more.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_selection	*move_display_left(t_selection *selection)
{
	t_selection *tmp;

	tmp = selection;
	while (tmp->vert_pos != -1)
	{
		tmp = tmp->next;
		selection = selection->prev;
	}
	return (selection);
}

int			move_cursor_right(t_selection **selection)
{
	t_selection	*cpy;

	cpy = get_under_cursor(selection);
	cpy->under_cursor = false;
	cpy->next->under_cursor = true;
	if (cpy->next->hor_pos == -1)
		*selection = cpy->next;
	return (0);
}

int			move_cursor_left(t_selection **selection)
{
	t_selection	*cpy;

	cpy = get_under_cursor(selection);
	cpy->under_cursor = false;
	cpy->prev->under_cursor = true;
	if (cpy->prev->hor_pos == -1)
		*selection = move_display_left(cpy);
	return (0);
}

t_selection	*set_cursor_on_pos(t_selection *cpy, int fnd_hor, int fnd_vert)
{
	cpy->under_cursor = false;
	while (!(cpy->vert_pos == fnd_vert && cpy->hor_pos == fnd_hor))
		cpy = cpy->prev;
	cpy->under_cursor = true;
	return (cpy);
}
