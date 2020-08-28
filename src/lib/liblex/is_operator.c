//
// Created by Darth Butterwell on 8/28/20.
//

#include "lexer.h"

int 		is_operator(t_token_type type)
{
	int index;

	index = 0;
	while (index < N_TOKEN_OPERATORS && index != (int) type)
		index++;
	if (index == N_TOKEN_OPERATORS)
		return (0);
	return (1);
}