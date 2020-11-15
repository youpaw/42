/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_check_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"
#include "cc_str.h"

static void	cd_usage_error_print(void)
{
	putendl("cd: usage: cd [-L|-P] [dir]");
}

int			cd_check_opt(const char **av, unsigned char *flags, int *er_code)
{
	t_parsed_opt	opt;
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
