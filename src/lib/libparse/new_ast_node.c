//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"
#include "cc.h"

t_ast				*new_ast_node(t_node_type type)
{
	t_ast *node;

	node = xmalloc(sizeof(t_ast));
	node->left = NULL;
	node->right = NULL;
	node->type = type;
	node->token = NULL;
	return (node);
}