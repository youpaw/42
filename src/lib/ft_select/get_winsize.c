/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 19:55:56 by mgena             #+#    #+#             */
/*   Updated: 2020/08/14 18:22:11 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

struct winsize	get_winsize(void)
{
	struct winsize ws;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	ws.ws_row /= 3;
	return (ws);
}
