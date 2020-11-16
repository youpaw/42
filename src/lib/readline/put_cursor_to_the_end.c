/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cursor_to_the_end.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	put_cursor_to_the_end(t_inp *inp)
{
	while (inp->line[inp->y_pos + 1])
		handle_shift_down(inp);
	while (inp->x_pos != inp->l_len[inp->y_pos])
		handle_right_arrow(inp);
}
