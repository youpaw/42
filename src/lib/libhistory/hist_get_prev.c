/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_get_prev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:06:52 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:06:55 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include <stddef.h>

char	*hist_get_prev(void)
{
	char	*str;

	if (g_hist.cur_ind == 0)
		return (NULL);
	vec_get_at(&str, g_hist.commands, --g_hist.cur_ind);
	return (str);
}
