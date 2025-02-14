/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "hash.h"
#include "cc_str.h"

static void	print_hashed(const char *av, t_hash_bin_pair *pair)
{
	pair->count++;
	puts(av);
	puts(" is hashed (");
	puts(pair->path);
	putendl(")");
}

static void	print_path(const char *av, const char *path)
{
	puts(av);
	puts(" is ");
	putendl(path);
}

static void	print_builtin(const char *av)
{
	puts(av);
	putendl(" is a shell builtin");
}

static int	print_err_not_found(const char *arg)
{
	const char	*err_args[2];

	err_args[0] = "type";
	err_args[1] = arg;
	error_print(E_NOTFOUND, err_args);
	return (1);
}

int			type(const char **av)
{
	char			*path;
	t_hash_bin_pair *pair;
	int				err;

	err = 0;
	while (*(++av))
	{
		if (get_builtin_index(*av) != -1)
			print_builtin(*av);
		else if ((pair = hash_map_get_val(g_hash, *av)))
			print_hashed(*av, pair);
		else if ((path = hash_get_bin_path(*av)))
		{
			print_path(*av, path);
			free(path);
		}
		else
			err = print_err_not_found(*av);
	}
	return (err);
}
