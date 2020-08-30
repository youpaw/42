//
// Created by Darth Butterwell on 8/26/20.
//

#include "lexer.h"
#include "cc_str.h"
#include "cc_num.h"

void 		print_tokens(t_tokens *tokens)
{
	size_t index;

	index = 0;
	while (index < tokens->size)
	{
		putnbr(index + 1);
		puts(". [ ");
		puts(tokens->tokens[index]->raw);
		puts(" ] [ ");
		puts(type_to_string(tokens->tokens[index]->type));
		puts(" ]\n");
		index++;
	}
}