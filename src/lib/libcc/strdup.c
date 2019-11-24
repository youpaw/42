/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:43:35 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/24 03:23:42 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc.h"

char	*strdup(const char *s1)
{
	char	*str;

	if (!(str = strnew(strlen(s1))))
		return (NULL);
	return (strcpy(str, s1));
}
