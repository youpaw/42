//
// Created by youpaw on 10.05.2020.
//

#ifndef LEX_RECOGNIZE_H
#define LEX_RECOGNIZE_H

#include "lexer.h"
#include "vector/cc_vec.h"


struct s_recognize{
	char *raw;
	size_t size;
	size_t index;
	enum e_state state;
	t_vec *tokens;
};

typedef struct s_recognize t_recognize;

int			recognize_tokens(t_tokens *tokens);

#endif //LEX_RECOGNIZE_H
