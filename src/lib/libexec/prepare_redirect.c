//
// Created by youpaw on 10/6/20.
//

#include "exec.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> // delete this

int 	prepare_redirect(t_ast *ast, t_process *process)
{
	size_t i;
	int		out;
	t_ast **redirects;

	i = 0;
	out = -1;
	if ((redirects = get_redirect_nodes(ast)) == NULL)
		return (0);
	while(redirects[i])
	{
		//need to check for stdio and if not change up descriptors!!
		// open?
		if (redirects[i]->token != NULL) // where redirection comes from
		{
			if (process->stdin != STDIN_FILENO)
				close(process->stdin);
			out = open(redirects[i]->token->raw, O_RDONLY);
			//if (-1 == out)
			//	open_error!!
			process->stdin = out;
		}
		if (redirects[i]->left)
		{
			//left leaf redirect type
		}
		if (redirects[i]->left->left)
		{
			// left left leaf (last one) where to redirect
		}
		if (redirects[i]->token)
		i++;
	}
	return (0);
}