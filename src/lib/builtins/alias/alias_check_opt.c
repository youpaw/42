//
// Created by Halfhand Lorrine on 10/25/20.
//

#include "alias_builtins.h"

int			alias_check_opt(t_opt_map builtin, const char **av,\
unsigned char *flags)
{
	t_parsed_opt 	opt;
	int				skip_args;
	char			opt_alias_map[N_ALIAS_BUILTINS][1];

	strcpy(opt_alias_map[0], "p");
	strcpy(opt_alias_map[1], "a");
	skip_args = optparse(av, opt_alias_map[builtin], &opt);
	if (isalpha(opt.invalid_opt))
	{
		alias_error_print(E_INVALOPT, (char *)builtin, &opt.invalid_opt);
		free(opt.options);
		return (-1);
	}
	if (skip_args > 1)
	{
		if (opt.options[strlen(opt.options) - 1] == opt_alias_map[builtin])
			*flags = ALIAS_BUILTINS_FLAG;
	}
	free(opt.options);
	return (skip_args);
}