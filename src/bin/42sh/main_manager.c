//
// Created by Darth Butterwell on 9/2/20.
//

#include "readline.h"
#include "lexer.h"
#include "cc_str.h"

int 	main_manager(void)
{
	t_tokens *tokens;
	char *str;

	str = strdup("");
	while (42)
	{
		readline(&str);
		tokens = validate_str(str);
		puts("\n");
		puts(str);
		puts("\n");
		print_tokens(tokens);
		if (tokens->error != E_NOINP)
		{
			free(str);
			str = strdup("");
		}
		destruct_tokens(&tokens);
	}
}
