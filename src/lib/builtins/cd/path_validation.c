//
// Created by slava-nya on 9/24/20.
//

#include "cd.h"

static int len_check(const char *cn_path)
{
	int cnt;
	int file_len;

	file_len = 0;
	cnt = 0;
	if (strlen(cn_path) >= MAX_PATH)
	{
		cd_error_print(E_NAMETOOLONG, cn_path);
		return (0);
	}
	while (cn_path[cnt])
	{
		if (file_len >= MAX_FILE)
		{
			cd_error_print(E_NAMETOOLONG, cn_path);
			return (0);
		}
		else if (cn_path[cnt] == '/')
			file_len = 0;
		file_len++;
		cnt++;
	}
	return (1);
}

static int valid_dir(const char *cn_path)
{
	struct	stat s;

	if (!*cn_path || stat(cn_path, &s))
	{
		cd_error_print(E_NOENT, cn_path);
		return (0);
	}
	if (!S_ISDIR(s.st_mode) && !S_ISLNK(s.st_mode))
	{
		cd_error_print(E_NOTDIR, cn_path);
		return (0);
	}
	if (access(cn_path, X_OK) != 0)
	{
		cd_error_print(E_ACCES, cn_path);
		return (0);
	}
	return (1);
}

static int envv_set(const char *cn_path)
{
	const char 	*(env_paths[N_PATHS]);

	env_paths[home] = env_get_value("HOME");
	env_paths[oldpwd] = env_get_value("OLDPWD");
	if (strcmp(cn_path, "-") == 0 && env_paths[oldpwd] == NULL)
	{
		cd_error_print(E_OLDPWDNOTSET, cn_path);
		return (0);
	}
	return (1);
}

int path_validation(const char *cn_path)
{
	if (!cn_path || !(*cn_path))
		return (0);
	if (!len_check(cn_path))
		return (1);
	if (!envv_set(cn_path))
		return (1);
	if (strcmp(cn_path, "-") == 0 && !valid_dir(cn_path))
		return (1);
	return (0);
}