//
// Created by Darth Butterwell on 8/7/20.
//

#include "lexer.h"
#include "cc_str.h"
#include "expand.h"

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
	if (index - 1)
	{
		lexer->raw[index - 1] = '\0';
		raw = nstrjoin(3, lexer->raw, expand, lexer->raw + lexer->index);
	}
	else
		raw = strjoin(expand, lexer->raw + lexer->index);
	lexer->index = index - 2;
	free(expand);
	free(lexer->raw);
	lexer->raw = raw;
	vec_rm_last(lexer->states);
	return (0);
}