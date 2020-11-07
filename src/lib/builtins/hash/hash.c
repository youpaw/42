//
// Created by Azzak Omega on 9/18/20.
//

#include "hash.h"
#include "optparse.h"
#include "error.h"

static int	print_error_option(char opt)
{
	char 		str[2];
	const char	*args[2];

	str[0] = opt;
	str[1] = '\0';
	args[0] = "hash";
	args[1] = str;
	error_print(E_INVALOPT, args);
	return (2);
}

static	int	update_hash(const char *bin)
{
	char	*path;

	if (!(path = hash_get_bin_path(bin)))
		return (E_NOTFOUND);
	hash_insert(bin, path);
	free(path);
	return (0);
}

static void	hash_remove_all(void)
{
	hash_map_del(&g_hash);
	hash_init();
}

int 	hash(const char **av)
{
	t_parsed_opt	opt_res;
	int 			skip;
	const char		*args[2];
	int 			err_code;

	if (!(skip = optparse(av, "r", &opt_res)))
		return (print_error_option(opt_res.invalid_opt));
	if (skip > 1)
		hash_remove_all();
	args[0] = "hash";
	err_code = 0;
	while (av[skip])
	{
		if (update_hash(av[skip]) == E_NOTFOUND)
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

