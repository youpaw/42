//
// Created by Halfhand Lorrine on 9/14/20.
//

#ifndef CD_H
#define CD_H

#include <sys/stat.h>
#include "builtins.h"
#include "stdio.h"
#include "cc.h"
#include "env.h"

# define N_PATHS 3
# define PATH_LEN 256

char I_AV = 0;
char FLAG = '0';

enum					e_paths
{
	home,
	pwd,
	oldpwd,
};

int					cd(const char **av);
void 				path_canonization(char *path);

#endif //CD_H
