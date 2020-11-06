//
// Created by Fidelia Mallister on 11/4/20.
//

#include "exec.h"
#include <unistd.h>
#include <fcntl.h>

int		redirect_less(t_ast *leafs, t_process *process) // c
{
	int in;
	int to;

	to = redirect_parse_left_side(leafs, 0);
	in = -1;
	if (leafs->left->left->token)
	{
		if (leafs->left->left->token->type == l_word)
		{
			if (!access(leafs->left->left->token->raw, R_OK))
			{
				in = open(leafs->left->left->token->raw, O_RDONLY);
				if (-1 == in)
					return (1); //open_error
				init_process_ioerr(process, to, in);
			}
			else
				return redirect_print_error(E_NOENT, leafs->left->left->token->raw); //errormsg: "42sh: %leafs->left->left->token->raw: no such file or directory"
		}
	}
	return (0);
}