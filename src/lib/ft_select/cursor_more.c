/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_more.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 15:07:55 by mgena             #+#    #+#             */
/*   Updated: 2020/08/14 15:08:04 by mgena            ###   ########.fr       */
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
	return(0);
}

int			move_cursor_left(t_selection **selection)
{
	t_selection	*cpy;

	cpy = get_under_cursor(selection);
	cpy->under_cursor = false;
	cpy->prev->under_cursor = true;
	if (cpy->prev->hor_pos == -1)
		*selection = move_display_left(cpy);
	return(0);
}

t_selection	*set_cursor_on_pos(t_selection *cpy, int fnd_hor, int fnd_vert)
{
	cpy->under_cursor = false;
	while (!(cpy->vert_pos == fnd_vert && cpy->hor_pos == fnd_hor))
		cpy = cpy->prev;
	cpy->under_cursor = true;
	return (cpy);
}
