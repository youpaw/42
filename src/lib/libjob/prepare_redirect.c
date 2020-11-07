//
// Created by youpaw on 10/6/20.
//

#include "exec.h"

static int		map_redirects(t_ast *ast, t_process *process)
{
	int		err;

	err = 0;
	if (ast->left->token->type == l_great)
		err = redirect_great(ast, process, 0);
	else if (ast->left->token->type == l_less)
		err = redirect_less(ast, process);
	else if (ast->left->token->type == l_double_great)
		err = redirect_great(ast, process, 1);
	else if (ast->left->token->type == l_great_and)
		err = redirect_great_and(ast, process);
	else if (ast->left->token->type == l_double_less)
		err = redirect_heredoc(ast, process);
	else if (ast->left->token->type == l_less_and)
		err = redirect_less_and(ast, process);
	return (err);
}

int				prepare_redirect(t_ast *ast, t_process *process)
{
	size_t		i;
	t_ast		**redirects;

	i = 0;
	if ((redirects = get_redirect_nodes(ast)) == NULL)
		return (0);
	while (redirects[i])
	{
		if (map_redirects(redirects[i], process) != 0)
			return (1);
		i++;
	}
	return (0);
}
