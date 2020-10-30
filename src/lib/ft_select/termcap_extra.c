/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 14:48:09 by mgena             #+#    #+#             */
/*   Updated: 2020/08/14 18:21:00 by mgena            ###   ########.fr       */
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

void	tinit(void)
{

		set_term_str();

}
