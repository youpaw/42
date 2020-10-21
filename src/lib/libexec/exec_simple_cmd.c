//
// Created by youpaw on 02.05.2020.
//

#include "exec.h"
#include "env.h"

static t_token_type get_redirect_type(t_token *redir_token)
{
	return (redir_token->type);
}

static void	fill_process_with_redirects(t_ast **redirects, t_process *process)
{
	size_t i;
	t_token_type redir;

	redir = 0;
	i = 0;
	while (redirects[i])
	{
		if (redirects[i]->type == p_io_redirect)
		{
			redir = get_redirect_type(redirects[i]->token);
			// TODO: switch redir and handle it's redirection
		}
		i++;
	}
}

void		exec_simple_cmd(t_ast *ast, t_process *process)
{
	t_ast **redirects;

	redirects = NULL;
	if (expand_ast(ast) || prepare_redirect(ast, process))
		return ;
	process->argv = get_args(ast);
	prepare_exec_env(ast->left);
	process->env = exec_env_2array();
	redirects = get_redirect_nodes(ast);
	fill_process_with_redirects(redirects, process);
	exec_env_del();
}
