/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_starts_with.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:19:06 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:19:08 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc.h"

int		str_starts_with(char const *str, const char *start)
{
	if (*str == 0 || *start == 0)
	{
		return (FALSE);
	}
	return (strncmp(str, start, strlen(start)) == 0);
}
