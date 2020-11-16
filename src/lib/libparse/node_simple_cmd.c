/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ast	*node_simple_cmd(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_simple_cmd);
	node->left = node_cmd_prefix(tokens);
	if (!get_node_token(node, tokens))
		node->right = node_cmd_suffix(tokens);
	else if (!node->left)
		del_ast(&node);
	return (node);
}
