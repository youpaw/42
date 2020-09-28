//
// Created by Darth Butterwell on 8/23/20.
//

#include "cd.h"

char CD_OPT = '0';


static void 		change_env(const char *cn_path, const char *oldpwd)
{
	char pwd[MAX_PATH];
	char *upd_pwd;
	char *upd_oldpwd;

	if (CD_OPT == 'P')
	{
		getcwd(pwd, MAX_PATH);
		upd_pwd = strjoin("PWD=", pwd);
		env_update(upd_pwd);
	}
	else
	{
		upd_pwd = strjoin("PWD=", cn_path);
		env_update(upd_pwd);
		getcwd(pwd, MAX_PATH);
//		puts("after pwd env: ");
//		upd_pwd = env_get_value("PWD");
//		putendl(upd_pwd);
//		puts("after pwd: ");
//		putendl(pwd);
	}
	upd_oldpwd = strjoin("OLDPWD=", oldpwd);
	env_update(upd_oldpwd);
//	puts("after oldpwd: ");
//	upd_oldpwd = env_get_value("OLDPWD");
//	putendl(upd_oldpwd);
	free(upd_pwd);
	free(upd_oldpwd);
}

static void 		run_chdir(const char *newpwd, const char *oldpwd,\
const char *path)
{
	char pwd[MAX_PATH];

	getcwd(pwd, MAX_PATH);
	if (chdir(newpwd) == 0)
	{
		change_env(newpwd, oldpwd);
		if (strcmp(path, "-") == 0)
			CD_OPT == 'P' ? putendl(pwd) : putendl(newpwd);
	}
}

static void			init_chdir(const char *cn_path, const char *path,\
 char *er_arr[2])
{
	char pwd[MAX_PATH];
	const char *home;
	const char *oldpwd;

	home = env_get_value("HOME");
	oldpwd = env_get_value("OLDPWD");
	getcwd(pwd, MAX_PATH);

//	puts("before pwd: ");
//	putendl(pwd);
//	puts("before oldpwd: ");
//	putendl(oldpwd);

	if (path == NULL)
		run_chdir(home, pwd, path);
	else
		run_chdir(cn_path, pwd, path);
	getcwd(pwd, MAX_PATH);
}

static int			check_opt(const char **av)
{
	t_parsed_opt 	opt;
	int				skip_args;
	char 			*er_arr[3];

	skip_args = optparse(av, "LP", &opt);
	if (isalpha(opt.invalid_opt))
	{
		er_arr[0] = av[0];
		er_arr[1] = memalloc(3);
		er_arr[1][0] = '-';
		er_arr[1][1] = opt.invalid_opt;
		er_arr[2] = NULL;
		error_print(E_INVALOPT, (const char **) er_arr);
		free(er_arr[1]);
		free(opt.options);
		return (-1);
	}
	if (skip_args > 1)
		CD_OPT = opt.options[strlen(opt.options) - 1];
	free(opt.options);
	putchar(CD_OPT);
	putchar('\n');
	return (skip_args);
}

int					cd(const char **av)
{
	int		path_i;
	char	*cn_path;
	char 	*er_arr[2];

	er_arr[0] = av[0];
	er_arr[1] = NULL;
	if (av[1] == NULL)
		init_chdir(NULL, NULL, av[0]);
	if ((path_i = check_opt(av)) < 1)
		return (1);
	cn_path = path_canonization(av[path_i]);
	if (path_validation(av, av[path_i], cn_path, path_i))
		return (1);
	init_chdir(cn_path, av[path_i], av[0]);
	free(cn_path);
	return (0);
}

