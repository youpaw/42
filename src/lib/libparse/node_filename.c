//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

t_ast		*node_filename(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_filename);
	if (get_node_token(node, tokens))
		del_ast(&node);
	return (node);
}
