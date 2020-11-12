//
// Created by Azzak Omega on 9/2/20.
//
#include "expand.h"
#include "error.h"
#include "stddef.h"
#include "stdlib.h"
#include "cc_str.h"
#include "cc_char.h"
#include "env.h"


static char	*param_or_word(const char *name, const char *word)
{
	char 	*value;

	if ((value = (char *)get_env_or_av_value(name)) && strlen(value))
		return (strdup(value));
	return (strdup(word));
}

static char	*assign_param(const char *name, const char *word)
{
	char 		*value;
	char 		*field;
	const char 	*arr[4];

	if ((value = (char *)get_env_or_av_value(name)) && strlen(value))
		return (strdup(value));
	arr[0] = name;
	arr[1] = "=";
	arr[2] = word;
	arr[3] = NULL;
	field = strnjoin(arr);
	env_update(field);
	free(field);
	return (strdup(word));
}

static char	*param_or_error(const char *name, const char *word)
{
	char		*value;
	const char	*err_args[2];

	err_args[0] = name;
	if ((value = (char *)get_env_or_av_value(name)) && strlen(value))
		return (strdup(value));
	if (word && strlen(word))
		err_args[1] = word;
	else
		err_args[1] = "parameter null or not set";
	error_print(E_EXPAND, err_args);
	return (NULL);
}

static char	*empty_or_word(const char *name, const char *word)
{
	char 	*value;

	if ((value = (char *)get_env_or_av_value(name)) && strlen(value))
		return (strdup(word));
	return (strnew(0));
}

char	*expand_by_type(t_param_type type, const char *name, const char *word)
{
	char 	*result;

	result = NULL;
	if (type == e_get_length)
		result = itoa((long long int)strlen(get_env_or_av_value(name)));
	else if (type == e_err_code)
		result = itoa((long long int)g_exit_code);
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
