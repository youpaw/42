/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoll.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 01:11:22 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/25 20:06:09 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_char.h"
#include <limits.h>

long long	atoll(const char *str)
{
	int			sig;
	long long	res;

	sig = 1;
	res = 0;
	while (isspace(*str))
		str++;
	if (*str == '-')
		sig = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && isdigit(*str))
	{
		if (sig > 0 && res > (LONG_MAX - (*str - '0')) / 10)
			return (LONG_MAX);
		if (sig < 0 && res * sig < (LONG_MIN + (*str - '0')) / 10)
			return (LONG_MIN);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sig);
}
