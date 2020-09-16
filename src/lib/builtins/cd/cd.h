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
# define MAX_PATH 256

enum					e_paths
{
	home,
	pwd,
	oldpwd,
};

typedef enum e_paths	t_paths;

int					cd(const char **av);
char				*path_canonization(char *path);

#endif //CD_H
