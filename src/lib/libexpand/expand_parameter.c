/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_parameter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "cc_str.h"
#include "error.h"
#include "expand.h"
#include "cc_char.h"

static char				*get_parameter_name(const char *str)
{
	const char	*head;

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

static size_t			get_operator_len(t_param_type t)
{
	if (t == e_get_length || t == e_default)
		return (0);
	if (t == e_rm_shortest_suffix || t == e_rm_shortest_prefix)
		return (1);
	return (2);
}

static t_param_type		get_len_operator_params(const char *str, char **name)
{
	if (!(*name = get_parameter_name(str)) || strcmp(str, *name) != 0)
		return (e_unknown);
	return (e_get_length);
}

static t_param_type		get_params(char *str, char **value, char **word)
{
	char			*name;
	t_param_type	type;

	if (*str == '#')
		return (get_len_operator_params(&str[1], value));
	if (!is_expand_err_code(str))
		return (e_err_code);
	if (!(name = get_parameter_name(str)))
		return (e_unknown);
	str += strlen(name);
	if ((type = get_operator_type(str)) == e_unknown)
	{
		free(name);
		return (e_unknown);
	}
	str += get_operator_len(type);
	*value = name;
	*word = strdup(str);
	return (type);
}

int						expand_parameter(char **str)
{
	t_param_type	type;
	char			*value;
	char			*word;
	const char		*arg[1];

	value = NULL;
	word = NULL;
	if ((type = get_params(*str, &value, &word)) == e_unknown)
	{
		arg[0] = *str;
		error_print(E_BADSUBS, arg);
		return (E_BADSUBS);
	}
	free(*str);
	*str = expand_by_type(type, value, word);
	if (value)
		free(value);
	if (word)
		free(word);
	if (!*str)
		return (E_EXPAND);
	return (0);
}
