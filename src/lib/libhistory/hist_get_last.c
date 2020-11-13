/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_get_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:06:40 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:06:43 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include <stddef.h>

char	*hist_get_last(void)
{
	char	*str;

	if (g_hist.commands->size < 1)
		return (NULL);
	vec_get_at(&str, g_hist.commands, g_hist.commands->size - 1);
	return (str);
}
