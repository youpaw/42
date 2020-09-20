//
// Created by Darth Butterwell on 9/2/20.
//

#include "env.h"
#include "readline.h"
#include "alias.h"
#include "history.h"
#include "cc_num.h"
#include "cc_str.h"
#include "hash.h"

static void change_shlvl(void)
{
	int 		n_lvl;
	char		*str_lvl;
	char		*field_lvl;

	if ((field_lvl = (char *)env_get_value("SHLVL")))
		n_lvl = atoi(field_lvl);
	else
		n_lvl = 0;
	str_lvl = itoa(n_lvl);
	if ((field_lvl = strjoin("SHLVL=", str_lvl)))
	{
		env_insert_to(g_env, field_lvl);
		free(field_lvl);
	}
	free(str_lvl);
}

int 	main_init(const char *name, const char *av[], const char *en[])
{
	g_exit_code = 0;
	av_init(name, av);
	env_init(en);
	hash_init();
	change_shlvl();
	alias_init();
	hist_init(env_get_value("HOME"));
	termcap_init();
	tty_init();
	return (0);
}