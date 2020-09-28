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
#include "optparse.h"
#include "error.h"

# define N_PATHS 3
# define MAX_PATH 256


enum					e_paths
{
	home,
	pwd,
	oldpwd,
};

typedef enum e_paths	t_paths;

char				*path_canonization(const char *path);
int					path_validation(char **av, char *path, char *cn_path, int path_i);



#endif //CD_H
