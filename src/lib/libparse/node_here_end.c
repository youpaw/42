//
// Created by Darth Butterwell on 10/17/20.
//

#include "parser.h"

t_ast		*node_here_end(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_here_end);
	if (get_node_token(node, tokens))
		del_ast(&node);
	return (node);
}
