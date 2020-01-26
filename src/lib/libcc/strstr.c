/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:00:11 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/25 20:06:09 by dbutterw         ###   ########.fr       */
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
char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i_needle;

	if (*needle == 0 || (*haystack == 0 && *needle == 0))
		return ((char *)haystack);
	if (*haystack == 0)
		return (NULL);
	i_needle = 0;
	while (*haystack != 0 && len-- > 0)
	{
		if (needle[i_needle] == 0)
			return ((char *)(haystack - i_needle));
		if (*haystack == needle[i_needle])
		{
			i_needle++;
		}
		else
		{
			len += i_needle;
			haystack -= i_needle;
			i_needle = 0;
		}
		haystack++;
	}
	return (needle[i_needle] == 0 ? (char *)(haystack - i_needle) : NULL);
}


char *strstr2(const char *haystack, const char *needle)
{
	return (ft_strnstr(haystack, needle, strlen(haystack) + 1));
}
