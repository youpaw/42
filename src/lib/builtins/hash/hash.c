/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:23:01 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 20:23:04 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "optparse.h"
#include "error.h"
#include "cc_str.h"

static int			print_error_option(char opt)
{
	print_invalid_option("hash", opt);
	return (2);
}

static int			update_hash(const char *bin)
{
	char			*path;

	if (!(path = hash_get_bin_path(bin)))
		return (E_NOTFOUND);
	hash_insert(bin, path);
	free(path);
	return (0);
}

static void			hash_remove_all(void)
{
	hash_map_del(&g_hash);
	hash_init();
}

static int			is_path(const char *str)
{
	if (*str == '/' || !strncmp(str, "./", 2) || !strncmp(str, "../", 3))
		return (1);
	return (0);
}

int					sh_hash(const char **av)
{
	t_parsed_opt	opt_res;
	int				skip;
	const char		*args[2];
	int				err_code;

	if (!(skip = optparse(av, "r", &opt_res)))
		return (print_error_option(opt_res.invalid_opt));
	if (skip > 1)
		hash_remove_all();
	args[0] = "hash";
	err_code = 0;
	while (av[skip])
	{
		if (update_hash(av[skip]) == E_NOTFOUND && !is_path(av[skip]))
		{
			err_code = E_NOTFOUND;
			args[1] = av[skip];
			error_print(E_NOTFOUND, args);
		}
		skip++;
	}
	if (skip == 1)
		return (hash_print());
	return (err_code ? 1 : 0);
}
