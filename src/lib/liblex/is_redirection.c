//
// Created by Darth Butterwell on 8/28/20.
//

#include "lexer.h"

int	is_redirection(t_token_type type)
{
	static const t_token_type redirection_map[N_TOKEN_REDIRECTIONS] = {
			l_less_and, l_great_and, l_less, l_great
	};
	int index;

	index = 0;
	while (index < N_TOKEN_REDIRECTIONS && type != redirection_map[index])
		index++;
	if (index == N_TOKEN_REDIRECTIONS)
		return (0);
	return (1);
}