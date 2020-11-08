//
// Created by Azzak Omega on 9/16/20.
//

#include "optparse.h"
#include "error.h"
#include "env_builtins.h"
#include "cc_hash_map.h"
#include "env.h"
#include "cc_str.h"

static int	print_error_option(char opt)
{
	char 		str[2];
	const char	*args[2];

	str[0] = opt;
	str[1] = '\0';
	args[0] = "export";
	args[1] = str;
	error_print(E_INVALOPT, args);
	return (E_INVALOPT);
}

static	int	try_export(const char *arg)
{
	t_hash_pair	pair;
	size_t		name_len;

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

int 	export(const char **av)
{
	t_parsed_opt	opt_res;
	int 			skip;
	const char		*args[2];
	int 			err_code;

	if (!(skip = optparse(av, "p", &opt_res)))
		return (print_error_option(opt_res.invalid_opt));
	if (!av[skip])
		return (print_exported_env());
	args[0] = "export";
	err_code = 0;
	while (av[skip])
	{
		if (try_export(av[skip]) == E_INVIDENT)
		{
			err_code = E_INVIDENT;
			args[1] = av[skip];
			error_print(E_INVIDENT, args);
		}
		skip++;
	}
	return (err_code);
}
