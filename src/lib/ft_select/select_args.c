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
#include "cc_str.h"
#include "cc_mem.h"

static int		select_handle_key(char *key)
{
	size_t								index;
	t_selection							*selection;
	static const t_key_select_handler	handlers[N_SELECT_KEY_HANDL_C] = {
			{"\t", move_cursor_right},
			{"\33\133\101", move_cursor_up},
			{"\33\133\102", move_cursor_down},
			{"\33\133\103", move_cursor_right},
			{"\33\133\104", move_cursor_left}
	};

	index = 0;
	selection = g_selection;
	while (index < N_SELECT_KEY_HANDL_C)
	{
		if (!strcmp(handlers[index].primary_key, key))
		{
			handlers[index].handler(&selection);
			g_selection = selection;
			return (0);
		}
		index++;
	}
	return (1);
}

char			*select_args(t_selection *selections)
{
	char	key[5];

	while (1)
	{
		bzero(key, 5);
		move_start();
		draw_selections(selections);
		if (read(STDIN_FILENO, key, 4) == -1)
			return (NULL);
		if (select_handle_key(key))
			return (strdup(key));
	}
}
