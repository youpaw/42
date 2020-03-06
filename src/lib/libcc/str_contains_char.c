/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_contains_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:14:24 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/25 20:06:09 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc.h"

int		str_contains_char(const char *str, const char c)
{
	while (*str != 0)
	{
		if (*str == c)
		{
			return (1);
		}
		str++;
	}
	return (0);
}
