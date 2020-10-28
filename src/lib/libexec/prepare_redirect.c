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
	int 	in;
	t_ast **redirects;
	int redirect_type;



	redirect_type = 0;
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
			in = open(redirects[i]->token->raw, O_RDONLY);
			//if (-1 == out)
			//	open_error!!
			process->stdin = in;
		}
		if (redirects[i]->left)
		{
			//left leaf redirect type
			if (redirects[i]->left->type == p_io_file)
			{
				if (redirects[i]->left->token->type == l_less)
					less_redirect(process);
				else if (redirects[i]->left->token->type == l_great)
					greater_redirect(process);
			}
		}
		if (redirects[i]->left->left)
		{
			if (redirects[i]->left->left->type == p_io_file)
			{
				if (redirects[i]->left->left->token->type == l_word)
				{
					if (process->stdout != STDOUT_FILENO)
						close(process->stdout);
					out = open(redirects[i]->left->left->token->raw, O_WRONLY | O_CREAT | O_TRUNC);
					//if (-1 == out)
					//	open_error!!!
					process->stdout = out;
				}
			}
		}
		// i don't actually know what I am doing...TO BE DONE TOMORROW!!!!
		i++;
	}
	return (0);
}