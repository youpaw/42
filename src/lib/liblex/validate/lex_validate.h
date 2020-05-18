//
// Created by youpaw on 11.05.2020.
//

#ifndef LEX_VALIDATE_H
#define LEX_VALIDATE_H
#define N_STACK_SIZE 5
#include "lexer.h"

struct s_validate{
	char *raw;
	char print_cmd;
	char expanding;
	size_t index;
	size_t size;
	enum e_state state;
};

typedef struct s_validate t_validate;

struct s_validate_map{
	char raw;
	enum e_state state;
	int (*handler)(t_validate *);
};

int 	v_handle_bs(t_validate *validate);
int 	v_handle_sq(t_validate *validate);
int		v_handle_dq(t_validate *validate);
int 	v_handle_us(t_validate *validate);
int 	v_handle_dollar(t_validate *validate);

static const struct s_validate_map g_validate_map[N_STATES] = {
		{'\\', l_back_slash, &v_handle_bs},
		{'\'', l_single_quote, &v_handle_sq},
		{'"', l_double_quote, &v_handle_dq},
		{'\0', l_unset, &v_handle_us}
};

int 	v_handle_bang(t_validate *validate);
int		validate_input(char **raw);

#endif //LEX_VALIDATE_H
