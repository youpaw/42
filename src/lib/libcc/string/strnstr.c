/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:15:30 by dbutterw          #+#    #+#             */
/*   Updated: 2020/01/06 14:39:22 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_str.h"
#include "cc_mem.h"
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

static char	*findstr(const char *haystack, const char *needle, const int *table, size_t len)
{
	int		ndcnt;
	size_t	hscnt;

	ndcnt = 0;
	hscnt = 0;
	while (haystack[hscnt] && hscnt < len)
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

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*res;
	int		*table;
	size_t	nlen;

	if (!(nlen = strlen(needle)))
		return ((char *)haystack);
	if (strlen(haystack) < nlen || len < nlen)
		return (NULL);
	table = (int*)xmalloc(sizeof(int) * nlen);
	init_table(needle, table);
	res = findstr(haystack, needle, table, len);
	free(table);
	return (res);
}
