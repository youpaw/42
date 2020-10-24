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
# define MAX_PATH 1024
# define MAX_FILE 256

#define CD_L_FLAG 00000001
#define CD_P_FLAG 00000010


enum					e_paths
{
	home,
	pwd,
	oldpwd,
};

typedef enum e_paths	t_paths;

char				*path_canonization(const char *path);
int path_validation(char **av, char *path);
int					check_opt(const char **av, unsigned char *flags);

#endif //CD_H
