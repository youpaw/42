/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:13:57 by mgena             #+#    #+#             */
/*   Updated: 2020/08/14 21:09:59 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		check_winsize(int len)
{
	int	screen_size;

	screen_size = get_winsize().ws_col;
	if (len <= 2)
	{
		g_out.flag_lil_wnd = true;
		ft_putstr_fd("..", g_out.fd);
		return (0);
	}
	else if (len > screen_size)
	{
		g_out.flag_lil_wnd = true;
		if (screen_size >= 13)
			ft_putstr_fd("Too few space", g_out.fd);
		else
			ft_putstr_fd("...", g_out.fd);
		return (0);
	}
	else
	{
		g_out.flag_lil_wnd = false;
		return (screen_size / (len + 1));
	}
}

void	restore_displayed(t_selection *selection)
{
	t_selection *cpy;

	cpy = selection;
	selection->hor_pos = -1;
	selection->vert_pos = -1;
	selection = selection->next;
	while (selection != cpy)
	{
		selection->hor_pos = -1;
		selection->vert_pos = -1;
		selection = selection->next;
	}
}
