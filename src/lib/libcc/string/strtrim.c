/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:47:13 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/25 20:06:09 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_str.h"
#include "cc_char.h"

char	*strtrim(char const *s)
{
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	len = strlen(s);
	while (i < len && isspace(s[i]))
		i++;
	while (len > i && isspace(s[len - 1]))
		len--;
	return (strsub(s, i, len - i));
}
