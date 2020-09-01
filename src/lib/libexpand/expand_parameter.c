//
// Created by Azzak Omega on 8/29/20.
//

#include "stdlib.h"
#include "cc_char.h"
#include "cc_str.h"
#include "env.h"

static size_t get_parameter_len(const char *str)
{
	const char *head = str;

	while (isdigit(*str))
		str++;
	if (str > head)
		return (str -head);
	while (isalnum(*str) || *str == '_')
		str++;
	return (str - head);
}

static size_t get_operator_len(const char *str)
{
	if (!*str)
		return (0);
	if (*str == ':' && (str[1] == '+' || str[1] == '-'
			|| str[1] == '?' || str[1] == '='))
		return (2);
	if (*str == '#')
	{
		if (str[1] == '#')
			return (2);
		return (1);
	}
	if (*str == '%')
	{
		if (str[1] == '%')
			return (2);
		return (1);
	}
	return (3);
}

static char *perform_expansion(const char *param, const char *oper,
							   const char *word)
{
	puts("p: ");
	putendl(param);
	puts("o: ");
	putendl(oper);
	puts("w: ");
	putendl(word);
	return (strnew(0));
}

static int replace(char **str, size_t par_len, size_t op_len)
{
	char	*param;
	char 	*oper;
	char 	*word;

	param = strsub(*str, 0, par_len);
	if (!op_len)
	{
		free(*str);
		*str = strdup(env_get_value(param));
		free(param);
		return (0);
	}
	oper = strsub(*str, par_len, op_len);
	word = strsub(*str, par_len + op_len,
			   strlen(*str) - par_len - op_len);
	free(*str);
	*str = perform_expansion(param, oper, word);
	free(param);
	free(oper);
	free(word);
	return (0);
}

int 	expand_parameter(char **str)
{
	size_t	parameter_len;
	size_t 	operator_len;

	if ((parameter_len = get_parameter_len(*str)))
		if ((operator_len = get_operator_len(*str + parameter_len)) <= 2)
			return (replace(str, parameter_len, operator_len));
	return (1);
}
