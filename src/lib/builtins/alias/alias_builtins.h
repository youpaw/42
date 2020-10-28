//
// Created by Halfhand Lorrine on 10/25/20.
//

#ifndef ALIAS_BUILTINS_H
#define ALIAS_BUILTINS_H

#include "builtins.h"
#include "alias.h"
#include "error.h"
#include "cc.h"
#include "optparse.h"

#define N_ALIAS_BUILTINS	2
#define ALIAS_BUILTINS_FLAG	00000001

typedef enum e_opt_map{
	ALIAS,					/* -p flag */
	UNALIAS,				/* -a flag */
}			t_opt_map;

void		alias_error_print(t_error_code er_code, const char *cmd,\

							  const char *arg);
int alias_check_opt(char *builtin, t_opt_map built_i, const char **av,
					unsigned char *flags);


#endif //ALIAS_BUILTINS_H
