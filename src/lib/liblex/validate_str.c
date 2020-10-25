//
// Created by Darth Butterwell on 9/13/20.
//

#include "lexer.h"
#include "cc_str.h"

t_tokens	*validate_str(const char *string)
{
	t_lexer		lexer;
	t_tokens	*tokens;
	int			error;

	if (!string || !*string)
		return (NULL);
	error = lex_err(&lexer, lex_raw(&lexer, string, l_vld));
	if (error == E_NOEVENT)
	{
		lex_del(&lexer);
		return (NULL);
	}
	if (!error && lexer.flags[l_print_command])
		putendl(lexer.raw);
	tokens = get_tokens(&lexer, error);
	lex_del(&lexer);
	return (tokens);
}