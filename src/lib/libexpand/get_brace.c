//
// Created by youpaw on 6/14/20.
//

#include "expand.h"
#include "string/cc_str.h"

const struct s_brace_raw g_brace_map[N_BRACES] = {
		{"((", "))"},
		{"(", ")"},
		{"{", "}"},
		{"[", "]"}
};

int get_brace(char *str, t_brace *brace)
{
	int cnt;

	cnt = 0;
	while (cnt < N_BRACES)
	{
		if (!strcmp(str, g_brace_map[cnt].open))
		{
			*brace = (t_brace)cnt;
			return (1);
		}
		else if (!strcmp(str, g_brace_map[cnt].close))
		{
			*brace = (t_brace)cnt;
			return (-1);
		}
		cnt++;
	}
	return (0);
}
