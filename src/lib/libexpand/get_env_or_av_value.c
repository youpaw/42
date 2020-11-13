//
// Created by Azzak Omega on 9/2/20.
//
#include "cc_char.h"
#include "env.h"

const char	*get_env_or_av_value(const char *name)
{
	if (isdigit(*name))
		return (av_get(atoi(name)));
	return (env_get_value(name));
}
