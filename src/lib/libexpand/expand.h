//
// Created by youpaw on 6/13/20.
//

#ifndef EXPAND_H
#define EXPAND_H
# define N_BRACES 3
# define N_STATES 5
# define STATES_STACK_SIZE 5
#include <stddef.h>
#include "vector/cc_vec.h"

enum e_state{
	e_back_slash,
	e_single_quote,
	e_double_quote,
	e_dollar,
	e_bang,
	e_unset
};

enum e_brace{
	e_round_brace,
	e_figure_brace,
	e_square_brace
};

struct s_expand{
	char			*raw;
	size_t			index;
	size_t			size;
	t_vec			*states;
};

typedef enum e_state t_state;
typedef enum e_brace t_brace;
typedef struct s_expand t_expand;

int		expand_raw(char **raw, int (*handler)(t_state, t_expand *),
			   int (*dollar_handler)(t_expand *));

int		expand_input_handler(t_state current, t_expand *expand);
int 	expand_input(char **raw);
int 	expand_exec_handler(t_expand *expand);
int 	expand_exec(char **raw);

void 	remove_quotes(char *raw);

struct s_brace_raw{
	char open;
	char close;
};

int		get_brace(char c, t_brace *brace);

# define	E_EXPAND 30
# define	E_NULL_INPUT E_EXPAND + 1
# define	E_INCOMPLETE_INPUT E_NULL_INPUT + 1
#endif //EXPAND_H
