//
// Created by youpaw on 30.05.2020.
//

#ifndef ENV_H
#define ENV_H
#define N_MAX_AV 254
#define N_MAX_EXEC_ENV 256
#define N_MAX_ENV 256

#include <glob.h>
#include "cc_hash_map.h"
extern int	g_exit_code;
extern char *g_av[N_MAX_AV];
extern t_hash_table *g_exec_env;
extern t_hash_table *g_env;

enum e_table_type{
	e_env,
	e_var
};

struct s_env{
	char *val;
	enum e_table_type type;
};

typedef enum e_table_type t_table_type;
typedef struct s_env t_env;

void		env_init(const char **env);
void		env_del(void);
void 		env_del_pair(t_hash_pair *pair);

size_t		get_name_length(const char *field);

t_env		*env_get_field(const char *name);
const char 	*env_get_field_val(const char *name);
int 		env_add_field(t_table_type type, const char *field);

void		exec_env_init(void);
int 		exec_env_add(const char *field);
char 		**exec_env_2array(void);

void 		av_init(const char *name, const char **av);
void 		av_set(const char **av);
const char	*av_get(int n);

void		print_env(void);
void		print_all(void);

#endif //ENV_H
