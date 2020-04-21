//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"
#include "cc.h"

int 		get_io_file_attr(t_ast *node, t_tokens *tokens, const char *attr)
{
	t_token token;

	token = tokens->tokens[tokens->index];
	if (str_equals(token.raw, attr))
	{
		node->attr = token;
		tokens->index++;
		return (1);
	}
	return (0);
}

t_ast *				node_io_file(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_io_file);
	if (get_io_file_attr(node, tokens, "<")
	|| get_token_attr(node, tokens, l_less_and)
	|| get_io_file_attr(node, tokens, ">")
	|| get_token_attr(node, tokens, l_great_and)
	|| get_token_attr(node, tokens, l_double_great)
	|| get_token_attr(node, tokens, l_less_great)
	|| get_token_attr(node, tokens, l_clobber))
	{
		if ((node->left = node_filename(tokens)))
			return (node);
	}
	del_ast_node(&node);
	return (NULL);
}