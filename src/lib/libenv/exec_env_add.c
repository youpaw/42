//
// Created by youpaw on 06.06.2020.
//

#include "env.h"
#include "string/cc_str.h"
#include <stdlib.h>

int 		exec_env_add(const char *field)
{
	int cnt;
	size_t name_len;

	if (!(name_len = get_name_length(field)))
		return (1);
	cnt = 0;
	while (g_exec_env[cnt] && strncmp(g_exec_env[cnt], field, name_len) != 0)
		cnt++;
	if (g_exec_env[cnt])
	{
		free(g_exec_env[cnt]);
		g_exec_env[cnt] = strdup(field);
	}
	else if (cnt < N_MAX_EXEC_ENV)
	{
		g_exec_env[cnt++] = strdup(field);
		g_exec_env[cnt] = NULL;
	}
	else
		return (1);
	return (0);
}
