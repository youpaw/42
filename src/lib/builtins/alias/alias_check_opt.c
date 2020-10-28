//
// Created by Halfhand Lorrine on 10/25/20.
//

#include "alias_builtins.h"

int alias_check_opt(char *builtin, t_opt_map built_i, const char **av,
					unsigned char *flags)
{
	t_parsed_opt 	opt;
	int				skip_args;
	char			opt_alias_map[N_ALIAS_BUILTINS][2];
	char			invalid_opt[2];

	strcpy(opt_alias_map[ALIAS], "p\0");
	strcpy(opt_alias_map[UNALIAS], "a\0");
	skip_args = optparse(av, opt_alias_map[built_i], &opt);
	if (isalpha(opt.invalid_opt))
	{
		invalid_opt[0] = opt.invalid_opt;
		invalid_opt[1] = '\0';
		alias_error_print(E_INVALOPT, builtin, invalid_opt);
		free(opt.options);
		return (-1);
	}
	if (skip_args > 1)
		if (opt.options[strlen(opt.options) - 1] == opt_alias_map[built_i][0])
			*flags = ALIAS_BUILTINS_FLAG;
	free(opt.options);
	return (skip_args);
}