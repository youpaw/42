/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:17:21 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/24 03:23:42 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc.h"

char		*strnew(size_t size)
{
	char	*res;

	res = xmalloc(size + 1);
	memset(res, 0, size + 1);
	return (res);
}