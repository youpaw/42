//
// Created by youpaw on 10/6/20.
//

#include "exec.h"

static void get_nodes_recursive(t_ast *ast, t_vec *vec)
{
	if (!ast)
		return ;
	if (ast->left && ast->left->type == p_io_redirect)
		vec_push(vec, &ast->left);
	get_nodes_recursive(ast->right, vec);
}

t_ast	**get_redirect_nodes(t_ast *ast)
{
	t_ast **redirect_nodes;
	t_vec *vec;

	redirect_nodes = NULL;
	vec = vec_new(EXEC_VEC_CAPACITY, sizeof(t_ast *), NULL);
	get_nodes_recursive(ast->left, vec);
	if (ast->left && ast->left->type == p_io_redirect)
		vec_push(vec, &ast->left);
	get_nodes_recursive(ast->right, vec);
	if (ast->right && ast->right->type == p_io_redirect)
		vec_push(vec, &ast->right);
	if (!vec->size)
		vec_del(&vec);
	else
	{
		redirect_nodes = (t_ast **)vec->data;
		free(vec);
	}
	return (redirect_nodes);
}
