//
// Created by slava-nya on 10/2/20.
//

#include "cd.h"

static void		cd_usage_error_print(void)
{
	putendl("cd: usage: cd [-L|-P] [dir]");
}

int cd_check_opt(const char **av, unsigned char *flags, int *er_code)
{
	t_parsed_opt 	opt;
	int				skip_args;

	skip_args = optparse(av, "LP", &opt);
	if (!skip_args)
	{
		*er_code = 1;
		print_invalid_option("cd", opt.invalid_opt);
		cd_usage_error_print();
		return (0);
	}
	if (skip_args > 1)
	{
		if (opt.options[strlen(opt.options) - 1] == 'P')
			*flags = CD_P_FLAG;
		free(opt.options);
	}
	return (skip_args);
}