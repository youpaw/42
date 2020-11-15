/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	set_term_str(void)
{
	g_out.reverse_video = tgetstr("mr", NULL);
	g_out.norm = tgetstr("me", NULL);
	g_out.hide_cursor = tgetstr("vi", NULL);
	g_out.show_cursor = tgetstr("ve", NULL);
	g_out.move_right = tgetstr("nd", NULL);
	g_out.move_down = tgetstr("do", NULL);
}
