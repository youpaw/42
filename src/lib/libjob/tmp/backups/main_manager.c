//
// Created by Darth Butterwell on 9/2/20.
//

#include "readline.h"
#include "exec.h"
#include "cc_str.h"
#include <unistd.h>

int 	main_manager(void)
{
	t_tokens *tokens;
	t_ast	*ast;
	char *str;

	ast = NULL;
	tokens = NULL;
	str = strnew(512);
	while (42)
	{
		//readline(&str);
		read(0, str, 512);
		tokens = validate_str(str);
		if (tokens && !tokens->error)
		{
			if ((ast = parse(tokens)))
				exec(ast);
		}
		if (!tokens || tokens->error != E_INCINP)
		{
			free(str);
			str = strnew(512);
			//str = strdup("");
		}
		del_ast(&ast);
		destruct_tokens(&tokens);
	}
}
