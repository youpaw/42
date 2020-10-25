//
// Created by slava-nya on 10/2/20.
//

#include "cd.h"

int			cd_check_opt(const char **av, unsigned char *flags)
{
	t_parsed_opt 	opt;
	int				skip_args;
	char			er_arg[3];

	skip_args = optparse(av, "LP", &opt);
	if (isalpha(opt.invalid_opt))
	{
		er_arg[0] = '-';
		er_arg[1] = opt.invalid_opt;
		er_arg[2] = '\0';
		cd_error_print(E_INVALOPT, er_arg);
		free(opt.options);
		return (-1);
	}
	if (skip_args > 1)
	{
		if (opt.options[strlen(opt.options) - 1] == 'P')
			*flags = CD_P_FLAG;
	}
	free(opt.options);
	return (skip_args);
}