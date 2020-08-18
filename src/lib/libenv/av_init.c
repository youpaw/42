//
// Created by youpaw on 06.06.2020.
//

#include "env.h"
#include "string/cc_str.h"

char *g_av[N_MAX_AV];

void	av_init(const char *name, const char **av)
{
	g_av[0] = strdup(name);
	av_set(av);
}
