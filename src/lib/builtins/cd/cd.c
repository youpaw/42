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
const char *path, unsigned char flags)
{
	char pwd[MAX_PATH];

	getcwd(pwd, MAX_PATH);
	if (chdir(newpwd) == 0)
	{
		change_env(newpwd, oldpwd, flags);
		if (strcmp(path, "-") == 0)
			flags & CD_P_FLAG ? putendl(pwd) : putendl(newpwd);
	}
}

static void			init_chdir(const char *cn_path, const char *path,\
 char *er_arr[2], unsigned char flags)
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
		run_chdir(home, pwd, path, flags);
	else
		run_chdir(cn_path, pwd, path, flags);
	getcwd(pwd, MAX_PATH);
}

int					cd(const char **av, char **env)
{
	int				path_i;
	char			*cn_path;
	char 			*er_arr[2];
	unsigned char 	flags;

	er_arr[0] = av[0];
	er_arr[1] = NULL;
	flags = CD_L_FLAG;
	if (av[1] == NULL)
		init_chdir(NULL, NULL, av[0], flags);
	if ((path_i = check_opt(av, &flags)) < 1)
		return (1);
	cn_path = path_canonization(av[path_i]);
	if (path_validation(av, av[path_i], cn_path, path_i))
		return (1);
	init_chdir(cn_path, av[path_i], av[0], flags);
	free(cn_path);
	return (0);
}

