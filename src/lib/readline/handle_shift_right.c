/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_shift_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "cc.h"

int	handle_shift_right(t_inp *inp)
{
	t_let let;

	let.ch[0] = !0;
	while (inp->x_pos != inp->l_len[inp->y_pos])
	{
		vec_get_at(&let, inp->line[inp->y_pos], inp->x_pos);
		if (isspace(let.ch[0]))
			break ;
		handle_right_arrow(inp);
	}
	while (inp->x_pos != inp->l_len[inp->y_pos])
	{
		vec_get_at(&let, inp->line[inp->y_pos], inp->x_pos);
		if (!isspace(let.ch[0]))
			break ;
		handle_right_arrow(inp);
	}
	return (0);
}
