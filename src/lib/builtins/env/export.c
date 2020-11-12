/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:22:14 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 20:22:18 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optparse.h"
#include "error.h"
#include "env_builtins.h"
#include "cc_hash_map.h"
#include "env.h"
#include "cc_str.h"

static int			try_export(const char *arg)
{
	t_hash_pair		pair;
	size_t			name_len;

	if (!(name_len = get_valid_name_length_no_check(arg)) ||
		(arg[name_len] && arg[name_len] != '='))
		return (E_INVIDENT);
	pair.key = strsub(arg, 0, name_len);
	pair.value = NULL;
	if (arg[name_len])
		pair.value = strdup(arg + name_len + 1);
	hash_map_del_one(g_inter_env, pair.key);
	return (hash_map_insert(g_env, &pair));
}

static int			check_opt(const char **av, char *opt, int *er_code)
{
	t_parsed_opt	opt_res;
	int				skip;

	if (!(skip = optparse(av, opt, &opt_res)))
	{
		print_invalid_option("export", opt_res.invalid_opt);
		*er_code = 2;
	}
	return (skip);
}

int					export(const char **av)
{
	int				skip;
	const char		*args[2];
	int				err_code;

	if (!(skip = check_opt(av, "p", &err_code)))
		return (err_code);
	if (!av[skip])
		return (print_exported_env());
	args[0] = "export";
	err_code = 0;
	while (av[skip])
	{
		if (try_export(av[skip]) == E_INVIDENT)
		{
			err_code = 1;
			args[1] = av[skip];
			error_print(E_INVIDENT, args);
		}
		skip++;
	}
	return (err_code);
}
