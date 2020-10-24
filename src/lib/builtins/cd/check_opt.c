//
// Created by slava-nya on 10/2/20.
//

#include "cd.h"

int			check_opt(const char **av, unsigned char *flags)
{
	t_parsed_opt 	opt;
	int				skip_args;
	char 			*er_arr[3];

	skip_args = optparse(av, "LP", &opt);
	if (isalpha(opt.invalid_opt))
	{
		er_arr[0] = av[0];
		er_arr[1] = memalloc(3);
		er_arr[1][0] = '-';
		er_arr[1][1] = opt.invalid_opt;
		er_arr[2] = NULL;
		error_print(E_INVALOPT, (const char **) er_arr);
		free(er_arr[1]);
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