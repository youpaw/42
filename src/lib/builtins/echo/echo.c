/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "error.h"
#include "echo.h"
#include "cc_str.h"
#include "cc_char.h"
#include "unistd.h"
#include "stdlib.h"

void				printspchars(char *str)
{
	size_t			cnt;

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

static int			check_opt(const char **av, unsigned char *flags)
{
	t_parsed_opt	opt;
	int				skip_args;

	skip_args = optparse(av, "en", &opt);
	if (skip_args > 1)
	{
		if (strchr(opt.options, 'n') != NULL)
			*flags |= ECHO_N_FLAG;
		if (strchr(opt.options, 'e') != NULL)
			*flags |= ECHO_E_LC_FLAG;
		free(opt.options);
	}
	if (skip_args == 0)
		return (1);
	return (skip_args);
}

static int			check_fd(void)
{
	const char		*error[2];
	struct stat		buf;

	if ((fstat(1, &buf)) != 0)
	{
		error[0] = "echo: write error";
		error[1] = NULL;
		error_print(E_BADFD, error);
		return (1);
	}
	return (0);
}

int					sh_echo(const char **av)
{
	unsigned char	flags;
	int				arg_cnt;

	if (check_fd())
		return (1);
	flags = ECHO_E_UPC_FLAG;
	arg_cnt = check_opt(av, &flags);
	while (av[arg_cnt])
	{
		if (flags & ECHO_E_LC_FLAG)
			printspchars((char *)av[arg_cnt]);
		else
			puts(av[arg_cnt]);
		if (av[arg_cnt + 1])
			putchar(' ');
		arg_cnt++;
	}
	if (!(flags & ECHO_N_FLAG))
		putchar('\n');
	return (0);
}
