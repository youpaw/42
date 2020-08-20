/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:42:30 by dbutterw          #+#    #+#             */
/*   Updated: 2020/01/06 14:39:22 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monetary.h>
#include "char/cc_char.h"

static int	fdputunsnbr(unsigned int n, int fd)
{
	static int cnt;

	cnt++;
	if (n > 9)
		fdputunsnbr(n / 10, fd);
	fdputchar(n % 10 + '0', fd);
	return (cnt);
}

ssize_t	fdputnbr(int n, int fd)
{
	unsigned int t;

	if (fd == -1)
		return (-1);
	if (n < 0)
	{
		fdputchar('-', fd);
		t = (unsigned int)(~n + 1);
	}
	else
		t = (unsigned int)n;
	return (fdputunsnbr(t, fd));
}
