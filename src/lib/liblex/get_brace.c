/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_brace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "cc_str.h"

const struct s_brace_raw g_brace_map[N_BRACES] =
{
	{"(", ")", 1},
	{"{", "}", 1},
	{"[", "]", 1}
};

int		get_brace(const char *str, t_brace *brace)
{
	int cnt;

	cnt = 0;
	while (cnt < N_BRACES)
	{
		if (!strncmp(str, g_brace_map[cnt].open, g_brace_map[cnt].len))
		{
			*brace = (t_brace)cnt;
			return (1);
		}
		else if (!strncmp(str, g_brace_map[cnt].close, g_brace_map[cnt].len))
		{
			*brace = (t_brace)cnt;
			return (-1);
		}
		cnt++;
	}
	return (0);
}
