//
// Created by youpaw on 06.06.2020.
//

#include <stdlib.h>
#include "env.h"
#include "cc_str.h"

void 		av_set(const char **av)
{
	int cnt;

	cnt = 1;
	while (cnt < N_MAX_AV && av[cnt])
	{
		if (g_av[cnt])
			free(g_av[cnt]);
		g_av[cnt] = strdup(av[cnt]);
		cnt++;
	}
	while (cnt < N_MAX_AV)
		g_av[cnt++] = NULL;
}