/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_get_by_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
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
