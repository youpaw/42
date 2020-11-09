//
// Created by Azzak Omega on 8/29/20.
//

#ifndef ALIAS_H
# define ALIAS_H
# define N_MAX_ALIAS 256

# include "cc_hash_map.h"

extern t_hash_map *g_aliases;

void		alias_init(void);
void		alias_del(void);
const char	*alias_get_value(const char *key);
int			alias_add(const char *field);
int			alias_remove(const char *key);
void		alias_print(void);
int			alias_cmp_pair(const t_hash_pair *lhs, const t_hash_pair *rhs);
void		alias_del_pair(t_hash_pair *pair);

#endif
