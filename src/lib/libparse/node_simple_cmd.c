//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

int			node_simple_cmd(t_tokens *tokens, t_ast **root)
{
	int		error;

	*root = new_ast_node(p_simple_cmd);
	if ((node_cmd_prefix(tokens, &(*root)->left)) < 0 ||\
		(error = get_node_token(*root, tokens)) < 0)
	{
		del_ast(root);
		return (-1);
	}
	if (error)
	{
		print_parse_error(tokens);
		return (1);
	}
	if (nod)
	{
		print_parse_error(tokens);
		del_ast(&node);
		return (NULL);
	}
	return (node);
}