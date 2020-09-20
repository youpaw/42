//
// Created by youpaw on 02.05.2020.
//

#include "exec.h"
#include "cc_mem.h"
#include "builtins.h"

static char **get_args(t_ast *ast)
{
	char **args;
	t_vec *args_vec;

	args_vec = vec_new(10, sizeof(char *), NULL);
	vec_push(args_vec, &ast->token->raw);
	ast = ast->right;
	while (ast)
	{
		if (ast->token->type == l_word)
			vec_push(args_vec, &ast->token->raw);
		ast = ast->left;
	}
	args = (char **) args_vec->data;
	free(args_vec);
	return (args);
}

void	exec_simple_cmd(t_ast *ast)
{
	char **args;

	args = get_args(ast);
	run_builtin((const char **) args);
	free(args);
}