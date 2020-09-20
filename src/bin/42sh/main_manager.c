//
// Created by Darth Butterwell on 9/2/20.
//

#include "readline.h"
#include "exec.h"
#include "cc_str.h"

int 	main_manager(void)
{
	t_tokens *tokens;
	t_ast	*ast;
	char *str;

	ast = NULL;
	tokens = NULL;
	str = strdup("");
	while (42)
	{
		readline(&str);
		tokens = validate_str(str);
		if (tokens && !tokens->error)
		{
			print_tokens(tokens);
			if ((ast = parse(tokens)))
				exec(ast);
		}
		else if (!tokens || tokens->error != E_INCINP)
		{
			free(str);
			destruct_tokens(&tokens);
			del_ast(&ast);
			str = strdup("");
		}
	}
}
