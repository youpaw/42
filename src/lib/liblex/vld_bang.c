//
// Created by Darth Butterwell on 8/7/20.
//

#include "lexer.h"
#include "cc_str.h"
#include "expand.h"

static char *str_join_expanded(t_lexer *lexer, size_t index, const char *expand)
{
	char *raw;
	const char *arr[4];

	if (index - 1)
	{
		arr[0] = lexer->raw;
		arr[1] = expand;
		arr[2] = lexer->raw + lexer->index;
		arr[3] = NULL;
		lexer->raw[index - 1] = '\0';
		raw = strnjoin(arr);
	}
	else
		raw = strjoin(expand, lexer->raw + lexer->index);
	lexer->index = index - 2;
	return (raw);
}

int 	vld_bang(t_lexer *lexer)
{
	char *expand;
	char *raw;
	size_t index;

	index = lexer->index;
	if (match_bang(lexer))
		return (1);
	expand = strsub(lexer->raw + index, 0, lexer->index - index);
	if (expand_bang(&expand))
	{
		free(expand);
		return (2);
	}
	raw = str_join_expanded(lexer, index, expand);
	free(expand);
	free(lexer->raw);
	lexer->raw = raw;
	vec_rm_last(lexer->states);
	return (0);
}