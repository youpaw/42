//
// Created by Halfhand Lorrine on 10/25/20.
//

#include "alias_builtins.h"

static void		value_parse(const char *arg)
{
	const char		*value;

	if ((value = alias_get_value(arg)) != NULL)
	{
		puts("alias ");
		putendl(value);
	}
	else
		alias_add(value);
}

int		alias(const char **av)
{
	unsigned char	flag;
	int				arg_i;

	flag = 0;
	if (!av[1])
	{
		alias_print();
		return (0);
	}
	if ((arg_i = alias_check_opt("alias", ALIAS, av, &flag)) < 1)
		return (1);
	if (flag == ALIAS_BUILTINS_FLAG || av[arg_i][0] == '#')
		alias_print();
	while (av[arg_i])
	{
		value_parse(av[arg_i]);
		arg_i++;
	}
	return (0);
}
