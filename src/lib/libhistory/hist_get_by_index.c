/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_get_by_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:06:28 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:06:32 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include <stddef.h>

char	*hist_get_by_index(int index)
{
	char	*str;

	if (index == 0 || index < -(int)(g_hist.commands->size) ||
						index > (int)(g_hist.commands->size))
		return (NULL);
	if (index > 0)
	{
		vec_get_at(&str, g_hist.commands, index - 1);
		return (str);
	}
	vec_get_at(&str, g_hist.commands, g_hist.commands->size + index);
	return (str);
}
