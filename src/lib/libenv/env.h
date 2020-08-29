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

/*
** funcs for av
 */

void		av_init(const char *name, const char **av);
const char	*av_get(int n);
void		av_del(void);

/*
** funcs for env
 */

void		env_init(const char **env);
void		env_del(void);
const char	*env_get_value(const char *key);
void		env_print_global(void);
void		env_print_full(void);


/*
** funcs for exec_env
 */

void		exec_env_init(void);
void		exec_env_del(void);
int 		exec_env_insert(const char *field);
char 		**exec_env_2array(void);


/*
** special funcs for env
 */

size_t		get_valid_name_length(const char *field);
void		env_print_pair(const t_hash_pair *pair);
void 		env_del_pair(t_hash_pair *pair);
int 		env_cmp_pair(const t_hash_pair *lhs, const t_hash_pair *rhs);

/*
** general funcs for env
 */

int 		env_insert_to(t_hash_map *hm, const char *field);
int 		env_remove_from(t_hash_map *hm, const char *key);

/*
** funcs for arr2
 */

void			arr2_del(char **arr);
size_t			arr2_get_size(const char **m);
void			arr2_print(const char **args, const char *st, const char *en);
void			arr2_quick_sort(void **items, int left, int right,
				int (*cmp)(const void *l, const void *r));


#endif //ENV_H
