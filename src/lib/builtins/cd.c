//
// Created by Darth Butterwell on 8/23/20.
//

#include <sys/stat.h>
#include "builtins.h"
#include "stdio.h"
#include "cc.h"

char P_FLAG = '0';

static int check_ac(const char *av)
{
	struct stat s;

	if (!*av || !lstat(av, &s))
	{
		putendl("bash: test: command not found");
		return (0);
	}
	if (!S_ISDIR(s.st_mode) && !S_ISLNK(s.st_mode))
	{
		putendl("bash: cd: p: Not a directory");
		return (0);
	}

}

static  int			check_P_flag(const char *av)
{
	int cnt;

	cnt = 1;
	while(av[cnt])
	{
		if (av[cnt] != 'P' && av[cnt] != 'L')
			return (1);
		cnt++;
	}
	if (av[1] == 'P')
		P_FLAG = '1';
}

int cd(int ac, const char **av)
{
//	int i = -1;
//	while (++i < ac)
//		printf(av[i]);

	if (ac >= 3 && av[2][0] == '-' && av[2][1])
	{
		if (!(check_P_flag(av[2])))
		{
			putendl("cd: usage: cd [-L|-P] [dir]");
			return (0);
		}
	}
		return (0);
}

