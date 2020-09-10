//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

int			node_complete_cmd(t_tokens *tokens, t_ast **root)
{
	int 	error;

	*root = new_ast_node(p_cmpl_cmd);
	error = node_list(tokens, &(*root)->left);
	return (error);
}