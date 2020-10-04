//
// Created by youpaw on 6/13/20.
//

#ifndef EXPAND_H
#define EXPAND_H
# define N_PARAM_TYPES 10

typedef enum	e_param_type
{
	e_er_bad_subst,
	e_er_syntax,
	e_default,
	e_param_or_word,
	e_assign_param,
	e_param_or_error,
	e_null_or_word,
	e_get_length,
	e_rm_shortest_prefix,
	e_rm_longest_prefix,
	e_rm_shortest_suffix,
	e_rm_longest_suffix
}				t_param_type;


/*
** funcs return error code or 0 (free str and replace with
**	malloced string)
*/

int 			expand_calc(char **str);
int 			expand_tilda(char **str);
int 			expand_bang(char **str);
int 			expand_parameter(char **str);
char			*expand_by_type(t_param_type type, const char *value, const char *word);
const char 		*get_env_or_av_value(const char *name);
char			*expand_suffix(const char *name, const char *pattern);
char			*expand_prefix(const char *name, const char *pattern);
t_param_type	get_operator_type(const char *str);

# define	E_EXPAND 30

#endif //EXPAND_H
