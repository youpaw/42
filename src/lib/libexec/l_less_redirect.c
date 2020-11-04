//
// Created by Fidelia Mallister on 11/4/20.
//

#include "exec.h"
#include <unistd.h>
#include <fcntl.h>

int		l_less_redirect(t_ast *leafs, t_process *process) // c
{
	int in;
	int to;

	to = left_side(leafs, 0);
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
				return (1); //errormsg: "42sh: %leafs->left->left->token->raw: no such file or directory"
		}
	}
	return (0);
}