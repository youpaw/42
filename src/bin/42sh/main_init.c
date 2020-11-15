/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "alias.h"
#include "history.h"
#include "cc_num.h"
#include "cc_str.h"
#include "hash.h"
#include "jobs.h"
#include <termcap.h>

static void	termcap_init(void)
{
	int error;

	error = tgetent(NULL, getenv("TERM"));
	if (error == 1)
		return ;
	else
	{
		if (error == 0)
			puts("Terminal recognition error\n"
		"Sorry, try another terminal\n");
		if (error == -1)
			puts("Terminal initialization error\n"
		"Sorry, check termcap file\n");
		else
			exit(0);
	}
}

static void	change_shlvl(void)
{
	int			n_lvl;
	char		*str_lvl;
	char		*field_lvl;

	if ((field_lvl = (char *)env_get_value("SHLVL")))
		n_lvl = atoi(field_lvl) + 1;
	else
		n_lvl = 1;
	str_lvl = itoa(n_lvl);
	if ((field_lvl = strjoin("SHLVL=", str_lvl)))
	{
		env_insert_to(g_env, field_lvl);
		free(field_lvl);
	}
	free(str_lvl);
}

int			main_init(const char *name, const char *av[], const char *en[])
{
	termcap_init();
	av_init(name, av);
	env_init(en);
	hash_init();
	change_shlvl();
	alias_init();
	hist_init(env_get_value("HOME"));
	jobs_init();
	return (0);
}
