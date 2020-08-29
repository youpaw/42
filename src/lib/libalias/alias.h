//
// Created by Azzak Omega on 8/29/20.
//

#ifndef ALIAS_H
#define ALIAS_H
#define N_MAX_ALIAS 256

#include "cc_hash_map.h"

extern t_hash_map *g_aliases;
/*
** alias management
 */

void		alias_init(void);
void		alias_del(void);
const char	*alias_get_value(const char *key);
int 		alias_add(const char *field);
int 		alias_remove(const char *key);
void		alias_print(void);


#endif //ALIAS_H
