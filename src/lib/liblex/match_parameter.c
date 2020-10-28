//
// Created by Darth Butterwell on 10/27/20.
//

#include "lexer.h"
#include "env.h"
#include "cc_char.h"

int			match_parameter(t_lexer *lexer)
{
	size_t len;

	if (isdigit(lexer->raw[lexer->index]) || lexer->raw[lexer->index] == '?')
		len = 1;
	else
		len = get_valid_name_length_no_check(lexer->raw + lexer->index);
	lexer->index += len;
	if (len)
		return (0);
	return (1);
}