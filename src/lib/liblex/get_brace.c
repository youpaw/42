//
// Created by youpaw on 13.05.2020.
//

#include "lexer.h"

int get_brace(char c, t_brace *brace)
{
	int cnt;

	cnt = 0;
	while (cnt < N_BRACES)
	{
		if (c == g_brace_map[cnt].open)
		{
			*brace = (t_brace)cnt;
			return (1);
		}
		else if (c == g_brace_map[cnt].close)
		{
			*brace = (t_brace)cnt;
			return (-1);
		}
		cnt++;
	}
	return (0);
}