/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:37:54 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 18:37:58 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"
#include "cc_str.h"
#include "unistd.h"

static void				change_env(const char *cn_path,\
						const char *oldpwd, unsigned char flags)
{
	char				pwd[MAX_PATH];
	char				*upd_pwd;
	char				*upd_oldpwd;

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

static	int				run_chdir(const char *newpwd, const char *oldpwd,\
						const char *path, unsigned char flags)
{
	char				pwd[MAX_PATH];

	getcwd(pwd, MAX_PATH);
	if (chdir(newpwd) == 0)
	{
		change_env(newpwd, oldpwd, flags);
		if (path != NULL && strcmp(path, "-") == 0)
			flags & CD_P_FLAG ? putendl(pwd) : putendl(newpwd);
	}
	else
		return (cd_error_print(E_NOENT, path));
	return (0);
}

static void				init_chdir(const char *cn_path, const char *path,\
						unsigned char flags, int *er_code)
{
	char				pwd[MAX_PATH];
	const char			*home;

	home = exec_env_get_value("HOME");
	getcwd(pwd, MAX_PATH);
	if (path == NULL || !*path)
	{
		if (home)
			*er_code = run_chdir(home, pwd, path, flags);
		else
			cd_error_print(E_HOMENOTSET, NULL);
	}
	else
		*er_code = run_chdir(cn_path, pwd, path, flags);
}

int						sh_cd(const char **av)
{
	int						path_i;
	char					*cn_path;
	unsigned char			flags;
	int						er_code;

	er_code = 0;
	flags = CD_L_FLAG;
	if (av[1] == NULL)
	{
		init_chdir(NULL, NULL, flags, &er_code);
		return (er_code);
	}
	if ((path_i = cd_check_opt(av, &flags, &er_code)) < 1 ||\
		!(av[path_i]))
		return (er_code);
	cn_path = cd_path_canonization(av[path_i]);
	if (cd_path_validation(cn_path, av[path_i]))
	{
		free(cn_path);
		return (1);
	}
	init_chdir(cn_path, av[path_i], flags, &er_code);
	free(cn_path);
	return (er_code);
}
