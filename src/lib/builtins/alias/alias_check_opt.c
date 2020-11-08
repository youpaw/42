//
// Created by Halfhand Lorrine on 10/25/20.
//

#include "alias_builtins.h"

int alias_check_opt(t_opt_map built_i, const char **av, unsigned char *flags)
{
	t_parsed_opt 	opt;
	int				skip_args;
	static const char	opt_alias_map[N_ALIAS_BUILTINS][2] = {"p\0", "a\0"};
	static const char	*built_map[N_ALIAS_BUILTINS] = {"alias", "unalias"};
	char			invalid_opt[2];


	skip_args = optparse(av, opt_alias_map[built_i], &opt);
	if (!skip_args)
	{
		invalid_opt[0] = opt.invalid_opt;
		invalid_opt[1] = '\0';
		alias_bash_error_print(E_INVALOPT, built_map[built_i], invalid_opt);
		return (-1);
	}
	if (skip_args > 1)
		if (opt.options[strlen(opt.options) - 1] == opt_alias_map[built_i][0])
			*flags = ALIAS_BUILTINS_FLAG;
	free(opt.options);
	return (skip_args);
}