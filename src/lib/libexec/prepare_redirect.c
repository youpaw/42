//
// Created by youpaw on 10/6/20.
//

#include "exec.h"

int 	prepare_redirect(t_ast *ast, t_process *process) // c
{
	size_t i;
	t_ast **redirects;
	int err;

	err = 0;
	i = 0;
	if ((redirects = get_redirect_nodes(ast)) == NULL)
		return (0);
	while(redirects[i])
	{
		if (redirects[i]->left->token)
		{
			if (redirects[i]->left->token->type == l_great)
				err = redirect_great(redirects[i], process, 0);
			else if (redirects[i]->left->token->type == l_less)
				err = redirect_less(redirects[i], process);
			else if (redirects[i]->left->token->type == l_double_great)
				err = redirect_great(redirects[i], process, 1);
			else if (redirects[i]->left->token->type == l_great_and)
			    err = redirect_great_and(redirects[i], process);
			else if (redirects[i]->left->token->type == l_heredoc)
				err = redirect_heredoc(redirects[i], process);
			else if (redirects[i]->left->token->type == l_less_and)
				err = redirect_less_and(redirects[i], process);
			if (err != 0)
				return (1);
		}
		i++;
	}
	return (0);
}