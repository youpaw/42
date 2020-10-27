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

//void	set_term_str(void)
//{
//	g_out.clear = tgetstr("cl", &g_out.p);
//	g_out.clear_after = tgetstr("cd", &g_out.p);
//	g_out.reverse_video = tgetstr("mr", &g_out.p);
//	g_out.underline = tgetstr("us", &g_out.p);
//	g_out.norm = tgetstr("me", &g_out.p);
//	g_out.hide_cursor = tgetstr("vi", &g_out.p);
//	g_out.show_cursor = tgetstr("ve", &g_out.p);
//	g_out.move_start = tgetstr("ho", &g_out.p);
//	g_out.move_right = tgetstr("nd", &g_out.p);
//	g_out.move_down = tgetstr("do", &g_out.p);
//}

//void	tinit(void)
//{
//	int error;
//
//	g_out.p = g_out.strings;
//	g_out.tname = getenv("TERM");
//	error = tgetent(g_out.tbuf, g_out.tname);
//	if (error == -1)
//	{
//		ft_printf("Нет файла TERMCAP\n");
//		exit(1);
//	}
//	else if (error == 0)
//	{
//		ft_printf("Терминал %s не описан\n", g_out.tname);
//		exit(2);
//	}
//	else if (error == 1)
//		set_term_str();
//	else
//	{
//		ft_printf("Unnamed error");
//		exit(1);
//	}
//}
