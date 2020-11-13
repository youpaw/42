/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_get_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:06:45 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:06:49 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include <stddef.h>

char	*hist_get_next(void)
{
	char	*str;

	if (g_hist.cur_ind == g_hist.commands->size - 1)
		g_hist.cur_ind++;
	if (g_hist.cur_ind == g_hist.commands->size)
		return (NULL);
	vec_get_at(&str, g_hist.commands, ++g_hist.cur_ind);
	return (str);
}
