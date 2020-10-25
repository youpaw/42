//
// Created by Darth Butterwell on 8/8/20.
//

#include "lexer.h"
#include "expand.h"
#include "cc_str.h"

static int handle_expand(t_brace brace, char **str)
{
	int error;

	error = 0;
	if (brace == l_figure_brace)
		error = expand_parameter(str);
	else if (brace == l_double_round_brace)
		error = expand_calc(str);
	return (error);
}

int 	exp_dollar(t_lexer *lexer)
{
	t_brace	brace;
	size_t	index;
	char	*sub;
	int		error;

	index = lexer->index + 1;
	get_brace(lexer->raw + lexer->index, &brace);
	match_brace(lexer, brace);
	sub = strsub(lexer->raw, index, lexer->index - index - 1);
	error = handle_expand(brace, &sub);
	if (!error)
		strjoin_expanded(lexer, index, sub, 2);
	free(sub);
	vec_rm_last(lexer->slices);
	return (error);
}
