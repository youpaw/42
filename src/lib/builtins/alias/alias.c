/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:39:43 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 18:39:46 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias_builtins.h"
#include "cc_str.h"

static void			alias_pint_pair(const char *key, const char *value)
{
	puts("alias ");
	puts(key);
	puts("='");
	puts(value);
	putendl("'");
}

static void			value_parse(const char *arg, int *er_code)
{
	const char		*value;

	if (strchr(arg, '=') != NULL)
	{
		if (alias_add(arg) == 1)
		{
			*er_code = 1;
			alias_bash_error_print(E_INVALALIAS, "alias", arg);
		}
		return ;
	}
	if ((value = alias_get_value(arg)) != NULL)
	{
		alias_pint_pair(arg, value);
		return ;
	}
	*er_code = 1;
	alias_bash_error_print(E_NOTFOUND, "alias", arg);
}

int					sh_alias(const char **av)
{
	unsigned char	flag;
	int				arg_i;
	int				er_code;

	er_code = 0;
	flag = 0;
	if (!av[1])
	{
		alias_print();
		return (er_code);
	}
	if ((arg_i = alias_check_opt(ALIAS, av, &flag, &er_code)) < 1)
		return (er_code);
	if (flag == ALIAS_BUILTINS_FLAG || av[arg_i][0] == '#')
		alias_print();
	while (av[arg_i])
	{
		value_parse(av[arg_i], &er_code);
		arg_i++;
	}
	return (er_code);
}
