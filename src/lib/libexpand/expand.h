//
// Created by youpaw on 6/13/20.
//

#ifndef EXPAND_H
#define EXPAND_H
# define N_BRACES 4
# define N_STATES 6
# define STATES_STACK_SIZE 5
# define BRACES_STACK_SIZE 5
# define N_EXPAND_FLAGS 1
# define N_EXPAND_STAGES 2
# define N_PARAM_TYPES 10
#include <stddef.h>
#include "cc_vec.h"

enum e_state{
	e_back_slash,
	e_single_quote,
	e_double_quote,
	e_dollar,
	e_bang,
	e_tilda,
	e_unset
};

enum e_brace{
	e_double_round_brace,
	e_round_brace,
	e_figure_brace,
	e_square_brace
};

enum e_stage{
	e_validate,
	e_expand
};

enum e_flag{
	e_print_command
};

struct s_handle{
	char			*raw;
	size_t			index;
	size_t			size;
	t_vec			*states;
	char 			flags[N_EXPAND_FLAGS];
	enum e_stage	stage;
};

typedef enum e_state t_state;
typedef enum e_brace t_brace;
typedef enum e_stage t_stage;
typedef struct s_handle t_handle;

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

int 	expand_back_slash(t_handle *handle);
int 	expand_tilda(t_handle *handle);
int 	expand_dollar(t_handle *handle);

int 	validate_back_slash(t_handle *handle);
int 	validate_single_quote(t_handle *handle);
int 	validate_double_quote(t_handle *handle);
int 	validate_bang(t_handle *handle);
int 	validate_dollar(t_handle *handle);

t_state	get_current_state(t_handle *expand);
int		handle_all(t_handle *handle, t_state current);
int		handle_raw(char **raw, t_stage stage);

struct s_brace_raw{
	char	*open;
	char	*close;
	int		len;
};

int		get_brace(char *str, t_brace *brace);

# define	E_EXPAND 30
# define	E_NULL_INPUT E_EXPAND + 1
# define	E_INCOMPLETE_INPUT E_NULL_INPUT + 1
# define	E_BAD_SUBSTITUTION E_INCOMPLETE_INPUT + 1
#endif //EXPAND_H
