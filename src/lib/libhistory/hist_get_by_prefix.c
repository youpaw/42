/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_get_by_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:06:34 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:06:37 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include "cc.h"

char	*hist_get_by_prefix(const char *prefix)
{
	int		i;
	size_t	len;
	char	*str;

	if (prefix)
	{
		len = strlen(prefix);
		i = g_hist.commands->size;
		while (--i >= 0)
		{
			vec_get_at(&str, g_hist.commands, i);
			if (strncmp(prefix, str, len) == 0)
				return (str);
		}
	}
	return (NULL);
}
