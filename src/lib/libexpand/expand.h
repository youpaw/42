//
// Created by youpaw on 6/13/20.
//

#ifndef EXPAND_H
#define EXPAND_H
# define N_PARAM_TYPES 10

//enum e_param_type
//{
//	e_default,
//	e_use_default,
//	e_assign_default,
//	e_display_error,
//	e_use_alternate,
//	e_get_length,
//	e_rm_shortest_prefix,
//	e_rm_longest_prefix,
//	e_rm_shortest_suffix,
//	e_rm_longest_suffix
//};
//
//typedef enum e_param_type t_param_type;


/*
** funcs return error code or 0 (free str and replace with
**	malloced string)
*/

int 	expand_tilda(char **str);
int 	expand_bang(char **str);
int 	expand_parameter(char **str);

# define	E_EXPAND 30

#endif //EXPAND_H
