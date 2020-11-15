/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optparse.h"
#include "error.h"
#include "env_builtins.h"
#include "cc_hash_map.h"
#include "env.h"
#include "cc_str.h"
#include "expand.h"

static char	*join_tilda(char *result, char *tilda, size_t index, size_t end)
{
	char		*raw;
	const char	*arr[4];

	if (index && result[index])
	{
		result[index] = '\0';
		arr[0] = result;
		arr[1] = tilda;
		arr[2] = result + end;
		arr[3] = NULL;
		raw = strnjoin(arr);
	}
	else if (!result[end])
	{
		result[index] = '\0';
		raw = strjoin(result, tilda);
	}
	else
		raw = strjoin(tilda, result + end);
	return (raw);
}

static void	expand_tildas(char **str)
{
	char	*result;
	char	*tilda;
	size_t	i;
	size_t	end;

	i = -1;
	result = *str;
	while (result[++i])
		if (result[i] == '~' && (!i || result[i - 1] == ':'))
		{
			end = i + 1;
			if (result[end] == '+' || result[end] == '-')
				end++;
			if (!result[end] || result[end] == '/' || result[end] == ':')
			{
				tilda = strsub(result, i, end - i);
				expand_tilda(&tilda);
				*str = join_tilda(result, tilda, i, end);
				free(result);
				free(tilda);
				result = *str;
			}
		}
}

static int	try_export(const char *arg)
{
	t_hash_pair	pair;
	size_t		name_len;

	if (!(name_len = get_valid_name_length_no_check(arg)) ||
		(arg[name_len] && arg[name_len] != '='))
		return (E_INVIDENT);
	pair.key = strsub(arg, 0, name_len);
	if (arg[name_len])
	{
		pair.value = strdup(arg + name_len + 1);
		expand_tildas((char **)&pair.value);
	}
	else
	{
		pair.value = (void *)env_get_value(pair.key);
		pair.value = pair.value ? strdup(pair.value) : NULL;
	}
	hash_map_del_one(g_inter_env, pair.key);
	return (hash_map_insert(g_env, &pair));
}

static int	check_opt(const char **av, char *opt, int *er_code)
{
	t_parsed_opt	opt_res;
	int				skip;

	if (!(skip = optparse(av, opt, &opt_res)))
	{
		print_invalid_option("export", opt_res.invalid_opt);
		print_usage(2, "export", "[name[=value] ...] or export -p");
		*er_code = 2;
	}
	free(opt_res.options);
	return (skip);
}

int			sh_export(const char **av)
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
