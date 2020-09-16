//
// Created by Darth Butterwell on 8/23/20.
//

#include "cd.h"

char I_AV = 0;
char FLAG = '0';

//static void 		get_chdir(char *newpwd, char *pwd, char *oldpwd)
//{
//
//}

//static void			init_chdir(const char *av)
//{
//	char 	*(paths[N_PATHS]);
//
//	paths[home] = env_get_value("HOME");
//	paths[pwd] = getcwd(paths[pwd], 0);
//	paths[oldpwd] = env_get_value("OLDPWD");
//
//
//	free(paths[pwd]);
//}
//
//static int			check_av(const char *av)
//{
//	struct stat s;
//
//	if (!*av || !lstat(av, &s))
//	{
//		putendl("bash: test: command not found");
//		return (1);
//	}
//	if (!S_ISDIR(s.st_mode) && !S_ISLNK(s.st_mode))
//	{
//		putendl("bash: cd: p: Not a directory");
//		return (1);
//	}
//	if (!S_ISLNK(s.st_mode) && access(av, R_OK) != 0)
//	{
//		putendl("bash: cd: p: Not a directory");
//		return (1);
//	}
//	if (access(av, X_OK) != 0)
//	{
//		putendl("cd: permission denied:");
//		return (1);
//	}
//	return (0);
//}
//
//static  int			check_flags(const char *av)
//{
//	int cnt;
//
//	cnt = 1;
//	while(av[cnt])
//	{
//		if (av[cnt] != 'P' && av[cnt] != 'L')
//		{
//			putendl("cd: usage: cd [-L|-P] [dir]");
//			return (1);
//		}
//		cnt++;
//	}
//	FLAG = av[1] == 'P' ? 'P' : 'L';
//	return (0);
//}

//int					cd(const char **av)
//{
//	if (av[2][0] == '-' && av[2][1]) //if ac>=3
//	{
//		if (check_flags(av[2]))
//			I_AV = FLAG != '0' ? 3 : 2;
//		else
//			return (1);
//	}
//	if (I_AV == 0 && !check_av(av[I_AV]))
//		return (1);
//	init_chdir(av[I_AV]);
//	return (0);
//}

