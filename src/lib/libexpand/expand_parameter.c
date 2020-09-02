//
// Created by Azzak Omega on 8/29/20.
//

#include "stdlib.h"
#include "cc_str.h"
#include "env.h"
#include "expand.h"
#include "cc_char.h"

static char *get_parameter_name(const char *str)
{
	const char *head;

	head = str;
	while (isdigit(*str))
		str++;
	if (str > head)
		return (strsub(head, 0, (str - head)));
	while (isalnum(*str) || *str == '_')
		str++;
	if (str > head)
		return (strsub(head, 0, (str - head)));
	return (NULL);
}

static t_param_type get_operator_type(const char *str)
{
	if (!*str)
		return (e_default);
	if (!strncmp(str, ":-", 2))
		return (e_param_or_word);
	if (!strncmp(str, ":=", 2))
		return (e_assign_param);
	if (!strncmp(str, ":?", 2))
		return (e_param_or_error);
	if (!strncmp(str, ":+", 2))
		return (e_null_or_word);
	if (!strncmp(str, "##", 2))
		return (e_rm_longest_prefix);
	if (!strncmp(str, "#", 1))
		return (e_rm_shortest_prefix);
	if (!strncmp(str, "%%", 2))
		return (e_rm_longest_suffix);
	if (!strncmp(str, "%", 1))
		return (e_rm_shortest_suffix);
	return (e_parse_error);
}

static size_t get_operator_len(t_param_type t)
{
	if (t == e_get_length)
		return (0);
	if (t == e_rm_shortest_suffix || t == e_rm_shortest_prefix)
		return (1);
	return (2);
}
static t_param_type get_params(const char *str, char **value, char **word)
{
	char 			*name;
	int 			is_get_len;
	t_param_type 	type;

	is_get_len = 0;
	if (*str == '#')
		is_get_len = 1;
	str += is_get_len;
	if (!(name = get_parameter_name(str)))
		return (e_parse_error);
	str += strlen(name);
	if ((type = get_operator_type(str)) == e_default && is_get_len)
		type = e_get_length;
	if (type == e_parse_error)
	{
		free(name);
		return (e_parse_error);
	}
	str += get_operator_len(type);
	*value = name;
	*word = strdup(str);
	return (type);
}

int 	expand_parameter(char **str)
{
	t_param_type	type;
	char 			*value;
	char 			*word;

	if ((type = get_params(*str, &value, &word)) == e_parse_error)
		return (1);
	free(*str);
	*str = expand_by_type(type, value, word);
	free(value);
	free(word);
	return (0);
}
