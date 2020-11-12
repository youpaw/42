//
// Created by Azzak Omega on 9/2/20.
//
#include "expand.h"
#include "cc_str.h"

char	*expand_prefix(const char *name, const char *pattern)
{
	const char	*value;
	size_t		len;

	if (!(value = get_env_or_av_value(name)))
		return (strnew(0));
	len = strlen(pattern);
	if (!strncmp(value, pattern, len))
		return (strsub(value, len, strlen(value) - len));
	return (strdup(value));
}
