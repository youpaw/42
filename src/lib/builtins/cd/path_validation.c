//
// Created by slava-nya on 9/24/20.
//

#include "cd.h"


//static int			chdir_test(char *path, char *cn_path, char *er_arr[3])
//{
//	char *test_path;
//
//	test_path = (!(*cn_path) ? path : cn_path);
//	if (chdir(test_path) != 0)
//	{
//		er_arr[1] = path;
//		error_print(E_NOENT, (const char **)er_arr);
//		return (1);
//	}
//	return (0);
//}

static int 			valid_dir(char *path, char *er_arr[3], char *cn_path)
{
	struct	stat s;

	er_arr[1] = path;
	if (!*path || lstat(path, &s))
	{
		error_print(E_NOENT, (const char **)er_arr);
		return (0);
	}
	if (!S_ISDIR(s.st_mode) && !S_ISLNK(s.st_mode))
	{
		error_print(E_NOTDIR, (const char **)er_arr);
		return (0);
	}
	if (!S_ISLNK(s.st_mode) && access(path, R_OK) != 0)
	{
		error_print(E_NOTDIR, (const char **)er_arr);
		return (0);
	}
	if (access(path, X_OK) != 0)
	{
		error_print(E_ACCES, (const char **)er_arr);
		return (0);
	}
	return (1);
}

static int 		envv_set(char *path, char *er_arr[3])
{
	const char 	*(env_paths[N_PATHS]);

	env_paths[home] = env_get_value("HOME");
	env_paths[oldpwd] = env_get_value("OLDPWD");
	if (env_paths[home] == NULL)
	{
		error_print(E_HOMENOTSET, (const char **) er_arr);
		return (0);
	}
	if (strcmp(path, "-") == 0 && env_paths[oldpwd] == NULL)
	{
		error_print(E_OLDPWDNOTSET, (const char **)er_arr);
		return (0);
	}
	return (1);
}

int path_validation(char **av, char *path, int path_i, char *cn_path)
{
	char	*er_arr[3];

	er_arr[0] = av[0];
	er_arr[1] = NULL;
	er_arr[2] = NULL;
	if (!path || !(*path))
		return (0);
//	if (av[path_i + 1] != NULL)
//	{
//		error_print(E_TOOMANYARGS, (const char **)er_arr);
//		return (1);
//	}
	if (!envv_set(path, er_arr))
		return (1);
//	if (chdir_test(path, cn_path, er_arr))
//		return (1);

	if (!valid_dir(path, er_arr, cn_path))
		return (1);
	return (0);
}