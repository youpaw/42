//
// Created by youpaw on 30.05.2020.
//

#ifndef ENV_H
#define ENV_H
#define N_MAX_AV 10
#define N_MAX_EXEC_ENV 1024

#include <glob.h>
#include "search/cc_avl.h"

static int	g_exit_code = 0;
static char *g_av[N_MAX_AV];
static char *g_exec_env[N_MAX_EXEC_ENV + 1];
static t_avl *g_env;

enum e_table_type{
	e_env,
	e_var
};

struct s_env{
	char *name;
	char *val;
	enum e_table_type type;
};

typedef enum e_table_type t_table_type;
typedef struct s_env t_env;

void		env_init(const char **env);
void		env_del(void);
int 		env_cmp(const t_env *src, const t_env *dst, void *params);

size_t		get_name_length(const char *field);

t_env		*env_get_field(const char *name);
const char 	*env_get_field_val(const char *name);
void		env_del_field(const char *name);
int 		env_add_field(t_table_type type, const char *field, int rewrite);

void		exec_env_init(void);
int 		exec_env_add(const char *field);

void 		av_init(const char *name, const char **av);
void 		av_set(const char **av);
const char	*av_get(int n);

void		print_env(void);
void		print_all(void);

#endif //ENV_H
