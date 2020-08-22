/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:13:55 by mgena             #+#    #+#             */
/*   Updated: 2020/08/22 14:48:26 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int symbol_key_pressed(t_input *inp, char key)
{
	ft_put(key);
	if (vec_push_at(inp->line, &key, inp->cursor_position))
		return (1);
	inp->cursor_position++;
	inp->len++;
	return (0);
}
