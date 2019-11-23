/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:00:11 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/24 00:33:34 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc.h"
#include <stdlib.h>

static void	init_table(const char *needle, int *table)
{
	int	pos;
	int	cnt;

	pos = 1;
	cnt = 0;
	table[0] = -1;
	while (needle[pos])
	{
		if (needle[pos] == needle[cnt])
			table[pos] = table[cnt];
		else
		{
			table[pos] = cnt;
			cnt = table[cnt];
			while (cnt >= 0 && needle[pos] != needle[cnt])
				cnt = table[cnt];
		}
		pos++;
		cnt++;
	}
}

static char	*findstr(const char *haystack, const char *needle, const int *table)
{
	int		ndcnt;
	size_t	hscnt;

	ndcnt = 0;
	hscnt = 0;
	while (haystack[hscnt])
	{
		if (needle[ndcnt] == haystack[hscnt])
		{
			ndcnt++;
			hscnt++;
			if (!needle[ndcnt])
				return ((char*)&haystack[hscnt - ndcnt]);
		}
		else if ((ndcnt = table[ndcnt]) < 0)
		{
			ndcnt++;
			hscnt++;
		}
	}
	return (NULL);
}

char		*strstr(const char *haystack, const char *needle)
{
	char	*res;
	int		*table;

	if (!haystack || !needle)
		return (NULL);
	if (!*needle)
		return ((char*)haystack);
	table = (int*)xmalloc(sizeof(char) * strlen(needle));
	init_table(needle, table);
	res = findstr(haystack, needle, table);
	free(table);
	return (res);
}
