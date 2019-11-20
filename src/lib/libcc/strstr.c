/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:00:11 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/20 21:00:11 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc.h"

char	*strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;

	if (!*haystack && !*needle)
		return ((char*)(haystack));
	j = 0;
	while (haystack[j])
	{
		i = 0;
		while (needle[i] && needle[i] == haystack[j])
		{
			j++;
			i++;
		}
		if (!needle[i])
			return ((char*)(haystack + j - i));
		j = j - i + 1;
	}
	return (NULL);
}
