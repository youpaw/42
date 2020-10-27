/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:46:29 by mgena             #+#    #+#             */
/*   Updated: 2020/08/14 20:48:06 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	abort_selections(t_selection **selection)
{
	t_selection *garbage;

	garbage = *selection;
	ft_fdprintf(g_out.fd, "%s%s%s", g_out.show_cursor, \
	g_out.move_start, g_out.clear_after);
	exit(0);
}

void	set_selection(t_selection **selection)
{
	t_selection	*s;

	s = *selection;
	while (!s->under_cursor)
		s = s->next;
	s->selected = !s->selected;
}

void	empty_function(void)
{
}

void	*get_key(char key[4])
{
	if (!ft_strcmp(key, "\33"))
		return (abort_selections);
	else if (!ft_strcmp(key, "\12"))
		return (NULL);
	else if (g_out.flag_lil_wnd)
	{
		ft_fdprintf(g_out.fd, "\7");
		return (empty_function);
	}
	else if (!ft_strcmp(key, " "))
		return (set_selection);
	else if (!ft_strcmp(key, "\177") ||
			(key[0] == 27 && key[1] == 91 && key[2] == 51 && key[3] == 126))
		return (delete_elem);
	else if (!ft_strcmp(key, "\33\133\101"))
		return (move_cursor_up);
	else if (!ft_strcmp(key, "\33\133\102"))
		return (move_cursor_down);
	else if (!ft_strcmp(key, "\33\133\103"))
		return (move_cursor_right);
	else if (!ft_strcmp(key, "\33\133\104"))
		return (move_cursor_left);
	return (empty_function);
}

char	*select_args(t_selection *selection)
{
	char	key[4];
	void	(*work_funct)(t_selection**);

	work_funct = NULL;
	while (1)
	{
		ft_bzero(key, 4);
		ft_putstr_fd(g_out.move_start, g_out.fd);
		ft_putstr_fd(g_out.clear_after, g_out.fd);
		draw_selections(selection);
		if (read(STDIN_FILENO, key, 4) == -1)
			escape();
		if ((work_funct = get_key(key)) == NULL)
			return (get_args_array(selection));
		work_funct(&selection);
		selection_storage(selection);
	}
}
