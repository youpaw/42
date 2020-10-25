//
// Created by slava-nya on 9/22/20.
//

#include "echo.h"


static int			check_opt(const char  **av, unsigned char *flags)
{
	t_parsed_opt 	opt;
	int				skip_args;

	skip_args = optparse(av, "en", &opt);
	if (skip_args > 1)
	{
		if (opt.options[0] == 'n')
			*flags = ECHO_N_FLAG;
	}
	free(opt.options);
	return (skip_args);
}

int					echo(const char **av)
{
	unsigned char	flags;
	int				arg_cnt;

	flags = ECHO_E_FLAG;
	arg_cnt = cd_check_opt(av, &flags);
	while (av[arg_cnt])
	{
		puts(av[arg_cnt]);
		if (av[arg_cnt + 1])
			putchar(' ');
		arg_cnt++;
	}
	if (flags & ECHO_E_FLAG)
		putchar('\n');
	return (0);
}