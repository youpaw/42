//
// Created by Darth Butterwell on 8/28/20.
//

#include "lexer.h"

int 	is_delimiter(t_token_type type)
{
	static const t_token_type delimiter_map[N_TOKEN_DELIMITERS] = {
			l_and_if, l_or_if, l_and, l_or, l_semi
	};
	int index;

	index = 0;
	while (index < N_TOKEN_DELIMITERS && type != delimiter_map[index])
		index++;
	if (index == N_TOKEN_DELIMITERS)
		return (0);
	return (1);
}