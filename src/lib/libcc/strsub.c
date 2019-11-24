/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 23:24:24 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/24 03:23:42 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc.h"

char	*strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (!s || !(sub = strnew(len)))
		return (NULL);
	return (strncpy(sub, &s[start], len));
}