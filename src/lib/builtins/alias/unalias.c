/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unalias.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:39:49 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 18:39:52 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias_builtins.h"

static void 	value_parse(const char *cmd, const char *arg, int *er_code)
{
	if (!(alias_remove(arg)))
		return;
	else
	{
		*er_code = 1;
		alias_bash_error_print(E_NOTFOUND, cmd, arg);
	}
}

int				unalias(const char **av)
{
	unsigned char	flag;
	int				arg_i;
	int 			er_code;

	er_code = 0;
	flag = 0;
	if (!av[1])
	{
		alias_usage_error_print("unalias", &er_code);
		return (er_code);
	}
	if ((arg_i = alias_check_opt(UNALIAS, av, &flag, &er_code)) < 1)
		return (er_code);
	if (flag == ALIAS_BUILTINS_FLAG)
	{
		alias_del();
		alias_init();
		return (er_code);
	}
	while (av[arg_i])
	{
		value_parse(av[0], av[arg_i], &er_code);
		arg_i++;
	}
	return (er_code);
}
