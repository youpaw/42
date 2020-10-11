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
			if ((ast = parse(tokens)))
				exec(ast, NULL);
		}
		if (!tokens || tokens->error != E_INCINP)
		{
			free(str);
			str = strdup("");
		}
		del_ast(&ast);
		destruct_tokens(&tokens);
	}
}
