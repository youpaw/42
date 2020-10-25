//
// Created by Darth Butterwell on 8/23/20.
//

#include "cd.h"

static void 		change_env(const char *cn_path, const char *oldpwd,\
unsigned char flags)
{
	char pwd[MAX_PATH];
	char *upd_pwd;
	char *upd_oldpwd;

	if (flags & CD_P_FLAG)
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
	}
	upd_oldpwd = strjoin("OLDPWD=", oldpwd);
	env_update(upd_oldpwd);
	free(upd_pwd);
	free(upd_oldpwd);
}

static void 		run_chdir(const char *newpwd, const char *oldpwd,\
const char *path, unsigned char flags)
{
	char pwd[MAX_PATH];

	getcwd(pwd, MAX_PATH);
	if (chdir(newpwd) == 0)
	{
		change_env(newpwd, oldpwd, flags);
		if (path != NULL && strcmp(path, "-") == 0)
			flags & CD_P_FLAG ? putendl(pwd) : putendl(newpwd);
	}
	else
		cd_error_print(E_NOENT, path);
}

static void			init_chdir(const char *cn_path, const char *path,\
unsigned char flags)
{
	char pwd[MAX_PATH];
	const char *home;

	home = env_get_value("HOME");
	getcwd(pwd, MAX_PATH);
	if (path == NULL)
	{
		if (home)
			run_chdir(home, pwd, path, flags);
		else
			cd_error_print(E_HOMENOTSET, NULL);
	}
	else
		run_chdir(cn_path, pwd, path, flags);
}

int cd(const char **av)
{
	int				path_i;
	char			*cn_path;
	unsigned char 	flags;

	flags = CD_L_FLAG;
	if (av[1] == NULL)
	{
		init_chdir(NULL, NULL, flags);
		return (0);
	}
	if ((path_i = cd_check_opt(av, &flags)) < 1 || !(*av[path_i]))
		return (1);
	cn_path = cd_path_canonization(av[path_i]);
	if (cd_path_validation(cn_path))
		return (1);
	init_chdir(cn_path, av[path_i], flags);
	free(cn_path);
	return (0);
}

