//
// Created by Darth Butterwell on 8/8/20.
//

#include "lexer.h"
#include "expand.h"
#include "cc_str.h"

static void	join_expansion(t_lexer *lexer, const char *sub, size_t index)
{
	const char	*arr[4];
	char		*raw;

	lexer->raw[index - 2] = '\0';
	arr[0] = lexer->raw;
	arr[1] = sub;
	arr[2] = lexer->raw + lexer->index;
	arr[3] = NULL;
	raw = strnjoin(arr);
	free(lexer->raw);
	lexer->raw = raw;
	lexer->index = index + strlen(sub) - 3;
}

static int expand_handler(t_lexer *lexer)
{
	t_brace	brace;
	size_t	index;
	char	*sub;
	int		error;

	error = 0;
	index = lexer->index + 1;
	get_brace(lexer->raw + lexer->index, &brace);
	match_brace(lexer, brace);
	sub = strsub(lexer->raw, index, lexer->index - index - 1);
	if (brace == l_figure_brace)
		error = expand_parameter(&sub);
	if (!error)
		join_expansion(lexer, sub, index);
	free(sub);
	return (error);
}

int 	exp_dollar(t_lexer *lexer)
{

	int		error;

	error = expand_handler(lexer);
	vec_rm_last(lexer->states);
	return (error);
}