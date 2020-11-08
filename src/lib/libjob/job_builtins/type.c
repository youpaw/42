//
// Created by Azzak Omega on 11/8/20.
//

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

int		type(const char **av)
{
	const char		*err_args[2];
	char 			*path;
	t_hash_bin_pair *pair;
	int 			err;

	err_args[0] = *av;
	err = 0;
	while (*(++av))
	{
		if (get_builtin_index(*av) != -1)
			print_builtin(*av);
		else if ((pair = hash_map_get_val(g_hash, *av)))
			print_hashed(*av, pair);
		else if ((path = hash_get_bin_path(*av)))
			print_path(*av, path);
		else
		{
			err = 1;
			err_args[1] = *av;
			error_print(E_NOTFOUND, err_args);
		}
	}
	return (err);
}
