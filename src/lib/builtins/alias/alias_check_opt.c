//
// Created by Halfhand Lorrine on 10/25/20.
//

#include "alias_builtins.h"
#include "cc_str.h"

int alias_check_opt(t_opt_map built_i, const char **av, unsigned char *flags,
					int *er_code)
{
	t_parsed_opt 		opt;
	int					skip_args;
	static const char	opt_alias_map[N_ALIAS_BUILTINS][2] = {"p\0", "a\0"};
	static const char	*built_map[N_ALIAS_BUILTINS] = {"alias", "unalias"};

	skip_args = optparse(av, opt_alias_map[built_i], &opt);
	if (!skip_args)
	{
		*er_code = 2;
		print_invalid_option(built_map[built_i], opt.invalid_opt);
		alias_usage_error_print(built_map[built_i], er_code);
		return (0);
	}
	if (skip_args > 1)
		if (opt.options[strlen(opt.options) - 1] == opt_alias_map[built_i][0])
			*flags = ALIAS_BUILTINS_FLAG;
	free(opt.options);
	return (skip_args);
}