//
// Created by youpaw on 06.06.2020.
//

#include "env.h"

const char	*av_get(int n)
{
	if (n >= 0 && n < N_MAX_AV)
		return (g_av[n]);
	return (NULL);
}
