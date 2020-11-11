//
// Created by slava-nya on 9/22/20.
//

#include <sys/stat.h>
#include "echo.h"

void		printspchars(char *str)
{
	size_t cnt;

	cnt = 0;
	while (str[cnt])
	{
		if (str[cnt] == '\\')
		{
			str += cnt;
			cnt = 0;
			if (!(str = handle_esc_chars(str)))
				return ;
		}
		if (str[cnt] && str[cnt] != '\\')
		{
			write(1, &str[cnt], 1);
			cnt++;
		}
	}
}

static int			check_opt(const char  **av, unsigned char *flags)
{
	t_parsed_opt 	opt;
	int				skip_args;

	skip_args = optparse(av, "en", &opt);
	if (skip_args > 1)
	{
		if (strchr(opt.options, 'n') != NULL)
			*flags |= ECHO_n_FLAG;
		if (strchr(opt.options, 'e') != NULL)
			*flags |= ECHO_e_FLAG;
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
	struct stat		buf;

	if ((fstat(1, &buf)) != 0)
	{
		putendl("lol");
		return (1);
	}
	flags = ECHO_E_FLAG;
	arg_cnt = check_opt(av, &flags);
	while (av[arg_cnt])
	{
		if (flags & ECHO_e_FLAG)
			printspchars((char *) av[arg_cnt]);
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