//
// Created by Darth Butterwell on 8/26/20.
//

#include "lexer.h"
#include "cc_str.h"

t_token_type get_operator(const char *str, t_operator *op)
{
	static const t_operator operator_map[N_TOKEN_OPERATORS] = {
			{"&&", 2},
			{"||", 2},
			{"<<", 2},
			{">>", 2},
			{"<&", 2},
			{">&", 2},
			{"&", 1},
			{"|", 1},
			{"<", 1},
			{">", 1},
			{";", 1},
			{"\n", 1}
	};
	int index;

	index = 0;
	while (index < N_TOKEN_OPERATORS && \
	strncmp(str, operator_map[index].operator, operator_map[index].size))
		index++;
	if (index == N_TOKEN_OPERATORS)
		return (l_token);
	*op = operator_map[index];
	return (index);
}