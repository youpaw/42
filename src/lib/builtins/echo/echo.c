//
// Created by slava-nya on 9/22/20.
//

#include "echo.h"

static void e_flag_print(char *str)
{
	size_t cnt;

	cnt = 0;
	while (str[cnt])
	{
		while (str[cnt] == '\\')
		{
			if (cnt)
				write(1, str, cnt);
			str += cnt;
			cnt = 0;
			if (!(str = handle_esc_chars(str)))
				return ;
		}
//		if (cnt)
//			write(1, str, cnt);
		if (str[cnt] && str[cnt] != '\\')
		{
			write(1, &str[cnt], 1);
			cnt++;
		}
	}
}

static int			echo_check_opt(const char  **av, unsigned char *flags)
{
	t_parsed_opt 	opt;
	int				skip_args;

	skip_args = optparse(av, "en", &opt);
	if (skip_args > 1)
	{
		if (opt.options[0] == 'n')
			*flags = ECHO_n_FLAG;
		else if (opt.options[0] == 'e')
			*flags = ECHO_e_FLAG;
		free(opt.options);
	}
	if (skip_args == 0)
		return (1);
	return (skip_args);
}

int					echo(const char **av)
{
	unsigned char	flags;
	int				arg_cnt;

	char *tmp = av[1];
	flags = ECHO_E_FLAG;
	arg_cnt = echo_check_opt(av, &flags);
	while (av[arg_cnt])
	{
		if (flags & ECHO_e_FLAG)
			e_flag_print((char *)av[arg_cnt]);
		else
			puts(av[arg_cnt]);
		if (av[arg_cnt + 1])
			putchar(' ');
		arg_cnt++;
	}
	if (!(flags & ECHO_n_FLAG))
		putchar('\n');
	return (0);
}