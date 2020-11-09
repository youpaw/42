//
// Created by youpaw on 30.05.2020.
//

#ifndef ENV_H
# define ENV_H
# define N_MAX_AV 254
# define N_MAX_EXEC_ENV 256
# define N_MAX_ENV 256

# include "cc_hash_map.h"
# include "cc_graph.h"

extern int			g_exit_code;
extern char			*g_av[N_MAX_AV];
extern t_hash_map	*g_exec_env;
extern t_hash_map	*g_inter_env;
extern t_hash_map	*g_env;

void				av_init(const char *name, const char **av);
const char			*av_get(int n);
void				av_del(void);

void				env_init(const char **env);
void				env_del(void); //unused
const char			*env_get_value(const char *key);
void				env_print_global(void); //unused
void				env_print_full(void);
int					env_update(const char *field);
int					env_export(const char *field);

void				exec_env_init(void);
void				exec_env_del(void);
int					exec_env_insert(const char *field);
char				**exec_env_2array(void);

size_t				get_valid_name_length(const char *field);
size_t				get_valid_name_length_no_check(const char *name);
void				env_print_pair(const t_hash_pair *pair);
void				env_del_pair(t_hash_pair *pair);
int					env_cmp_pair(const t_hash_pair *lhs,
					const t_hash_pair *rhs);
const char			**get_all_env_names_sorted(void);

int					env_insert_to(t_hash_map *hm, const char *field);
int					env_remove_from(t_hash_map *hm, const char *key);

void				fill_graph_by_env_names(t_graph *graph);

#endif
