/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:16:18 by dbutterw          #+#    #+#             */
/*   Updated: 2020/01/06 14:39:22 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_str.h"

static int	intlen(long long int n)
{
	int		len;

	if (n < 0)
		len = 1;
	else
		len = 0;
	while (n > 9 || n < -9)
	{
		len++;
		n /= 10;
	}
	return (++len);
}

char		*itoa(long long int n)
{
	size_t	t;
	char	*str;
	int		size;

	size = intlen(n);
	if (n < 0)
		t = (size_t)(~n + 1);
	else
		t = (size_t)n;
	if (!(str = strnew(size)))
		return (NULL);
	while (t > 9)
	{
		str[--size] = t % 10 + '0';
		t /= 10;
	}
	str[--size] = t % 10 + '0';
	if (size)
		str[size - 1] = '-';
	return (str);
}
