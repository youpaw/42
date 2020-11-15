/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_shift_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "cc.h"

int	handle_shift_left(t_inp *inp)
{
	t_let let;

	let.ch[0] = !0;
	while (inp->x_pos - get_prompt_len(inp->y_pos))
	{
		vec_get_at(&let, inp->line[inp->y_pos], inp->x_pos);
		if (isspace(let.ch[0]))
			break ;
		handle_left_arrow(inp);
	}
	while (inp->x_pos != inp->l_len[inp->y_pos])
	{
		vec_get_at(&let, inp->line[inp->y_pos], inp->x_pos);
		if (!isspace(let.ch[0]))
			break ;
		handle_left_arrow(inp);
	}
	return (0);
}
