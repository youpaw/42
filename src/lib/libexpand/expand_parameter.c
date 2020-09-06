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

static size_t get_operator_len(t_param_type t)
{
	if (t == e_get_length)
		return (0);
	if (t == e_rm_shortest_suffix || t == e_rm_shortest_prefix)
		return (1);
	return (2);
}

static t_param_type get_len_operator_params(const char *str, char **name,
											char **word)
{
	if (!(*name = get_parameter_name(str)) || strcmp(str, *name) != 0)
		return (e_er_bad_subst);
	return (e_get_length);
}
static t_param_type get_params(const char *str, char **value, char **word)
{
	char 			*name;
	t_param_type 	type;

	if (*str == '#')
		return (get_len_operator_params(&str[1], value, word));
	if (!(name = get_parameter_name(str)))
		return (e_er_bad_subst);
	str += strlen(name);
	if ((type = get_operator_type(str)) == e_er_bad_subst)
	{
		free(name);
		return (e_er_bad_subst);
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

	value = NULL;
	word = NULL;
	if ((type = get_params(*str, &value, &word)) < 2)
		return (1);
	free(*str);
	*str = expand_by_type(type, value, word);
	if (value)
		free(value);
	if (word)
		free(word);
	return (0);
}
