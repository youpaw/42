/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 03:17:39 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/25 20:06:09 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NULL ((void *)0)

char	*strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s++ == (char)c)
			return ((char*)(s - 1));
	}
	if (*s == (char)c)
		return ((char*)s);
	else
		return (NULL);
}
