//
// Created by Azzak Omega on 9/2/20.
//
#include "expand.h"
#include "stddef.h"
#include "stdlib.h"
#include "cc_str.h"
#include "cc_char.h"
#include "env.h"


static char	*param_or_word(const char *name, const char *word)
{
	char 	*value;

	if ((value = (char *)get_env_or_av_value(name)) && !strlen(value))
		strdel(&value);
	if (value)
		return (strdup(value));
	return (strdup(word));
}

static char	*assign_param(const char *name, const char *word)
{
	char 	*value;

	if ((value = (char *)get_env_or_av_value(name)) && !strlen(value))
		strdel(&value);
	if (value)
		return (strdup(value));
	// env insert word for name
	return (strdup(word));
}

static char	*param_or_error(const char *name, const char *word)
{
	char 	*value;

	if ((value = (char *)get_env_or_av_value(name)) && !strlen(value))
		strdel(&value);
	if (value)
		return (strdup(value));
	if (word && strlen(word))
		fdputendl(word, 2);
	else
		fdputendl("bash: : parameter null or not set", 2);
	return (strnew(0));
}

static char	*empty_or_word(const char *name, const char *word)
{
	char 	*value;

	if ((value = (char *)get_env_or_av_value(name)) && !strlen(value))
		strdel(&value);
	if (value)
		return (strdup(word));
	return (strnew(0));
}

char	*expand_by_type(t_param_type type, const char *name, const char *word)
{
	char 	*result;

	result = NULL;
	if (type == e_get_length)
		result = itoa((long long int)strlen(get_env_or_av_value(name)));
	else if (type == e_default)
		result = param_or_word(name, "");
	else if (type == e_param_or_word)
		result = param_or_word(name, word);
	else if (type == e_assign_param)
		result = assign_param(name, word);
	else if (type == e_param_or_error)
		result = param_or_error(name, word);
	else if (type == e_null_or_word)
		result = empty_or_word(name, word);
	else if (type == e_rm_shortest_prefix || type == e_rm_longest_prefix)
		result = expand_prefix(name, word);
	else if (type == e_rm_shortest_suffix || type == e_rm_longest_suffix)
		result = expand_suffix(name, word);
	return (result);
}
