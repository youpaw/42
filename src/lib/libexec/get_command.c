//
// Created by youpaw on 10/11/20.
//

#include "exec.h"
#include "cc_str.h"

static void get_node_tokens(t_ast *ast, t_vec *vec)
{
	static char *delimiter = " ";

	if (!ast)
		return ;
	get_node_tokens(ast->left, vec);
	if (ast->token)
	{
		vec_push(vec, &ast->token->raw);
		vec_push(vec, &delimiter);
	}
	get_node_tokens(ast->right, vec);
}

char *get_command(t_ast *ast)
{
	char *command;
	t_vec *vec;

	vec = vec_new(JOB_VEC_CAPACITY, sizeof(char *), NULL);
	get_node_tokens(ast, vec);
	command = strnjoin((const char **)vec->data);
	vec_del(&vec);
	return (command);
}