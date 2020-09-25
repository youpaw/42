//
// Created by youpaw on 9/24/20.
//
#include "lexer.h"
#include "cc_str.h"

void	strjoin_expanded(t_lexer *lexer, size_t index, const char *expand, int pad)
{
	char		*raw;
	const char *arr[4];

	if (index - pad && lexer->index < lexer->size)
	{
		arr[0] = lexer->raw;
		arr[1] = expand;
		arr[2] = lexer->raw + lexer->index;
		arr[3] = NULL;
		lexer->raw[index - pad] = '\0';
		raw = strnjoin(arr);
	}
	else if (lexer->index == lexer->size)
	{
		lexer->raw[index - pad] = '\0';
		raw = strjoin(lexer->raw, expand);
	}
	else
		raw = strjoin(expand, lexer->raw + lexer->index);
	lexer->index = index - pad - 1;
	lexer->size = strlen(lexer->raw);
	free(lexer->raw);
	lexer->raw = raw;
}
