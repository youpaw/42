//
// Created by youpaw on 06.06.2020.
//

#include "env.h"
#include "string/cc_str.h"

int 	env_cmp(const t_env *src, const t_env *dst, void *params)
{
	(void)params;
	return (strcmp(src->name, dst->name));
}
