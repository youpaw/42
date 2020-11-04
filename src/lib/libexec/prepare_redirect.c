//
// Created by youpaw on 10/6/20.
//

#include "exec.h"
#include <cc_str.h> // delete ???

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
				err = l_great_redirect(redirects[i], process, 0);
			else if (redirects[i]->left->token->type == l_less)
				err = l_less_redirect(redirects[i], process);
			else if (redirects[i]->left->token->type == l_double_great)
				err = l_great_redirect(redirects[i], process, 1);
			else if (redirects[i]->left->token->type == l_great_and)
			    err = l_great_and_redirect(redirects[i], process);
			else if (redirects[i]->left->token->type == l_heredoc)
				err = l_heredoc_redirect(redirects[i], process);
			if (err == 1)
				return (1);
		}
		i++;
	}
	return (0);
}