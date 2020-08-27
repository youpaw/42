//
// Created by youpaw on 30.05.2020.
//

#ifndef ENV_H
#define ENV_H
#define N_MAX_AV 254
#define N_MAX_EXEC_ENV 256
#define N_MAX_ENV 256

//#include <glob.h>
#include "cc_hash_map.h"
extern int	g_exit_code;
extern char *g_av[N_MAX_AV];
extern t_hash_map *g_exec_env;
extern t_hash_map *g_inter_env;
extern t_hash_map *g_env;

void		env_init(const char **env);
void		env_del(void);
void		exec_env_del(void);
void		env_print_pair(const t_hash_pair *pair);
void 		env_del_pair(t_hash_pair *pair);
int 		env_cmp_pair(const t_hash_pair *lhs, const t_hash_pair *rhs);
const char	*env_get_value(const char *key);

size_t		get_valid_name_length(const char *field);

void		exec_env_init(void);
int 		exec_env_add(const char *field);
char 		**exec_env_2array(void);

void		env_print_global(void);
void		env_print_full(void);

/*
** general funcs for env_hm manipulation
 */

int 		env_insert_to(t_hash_map *hm, const char *field);
int 		env_remove_from(t_hash_map *hm, const char *key);
#endif //ENV_H
