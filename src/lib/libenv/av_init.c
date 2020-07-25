//
// Created by youpaw on 06.06.2020.
//

#include "env.h"
#include "string/cc_str.h"

char *g_av[N_MAX_AV];

void	av_init(const char *name, const char **av)
{
	int cnt;

	cnt = 0;
	g_av[cnt++] = strdup(name);
	while (cnt < N_MAX_AV)
		g_av[cnt++] = NULL;
	av_set(av);
}
