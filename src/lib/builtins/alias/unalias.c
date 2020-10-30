//
// Created by Halfhand Lorrine on 10/25/20.
//

#include "alias_builtins.h"

static void		value_parse(const char *cmd, const char *arg)
{
	if (!(alias_remove(arg)))
		return;
	else
		alias_error_print(E_NOTFOUND, cmd, arg);
}

int		unalias(const char **av)
{
	unsigned char	flag;
	int				arg_i;

	flag = 0;
	if (!av[1])
	{
		alias_error_print(E_ARGCNOTENOUGH, av[0], NULL);
		return (0);
	}
	if ((arg_i = alias_check_opt("unalias", UNALIAS, av, &flag)) < 1)
		return (1);
	if (flag == ALIAS_BUILTINS_FLAG)
	{
		alias_del();
		return (0);
	}
	while (av[arg_i])
	{
		value_parse(av[0], av[arg_i]);
		arg_i++;
	}
	return (0);
}
