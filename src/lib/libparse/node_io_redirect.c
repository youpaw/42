/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_io_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ast		*node_io_redirect(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_io_redirect);
	get_node_token(node, tokens);
	if (!(node->left = node_io_file(tokens)) &&
	!(node->left = node_io_here(tokens)))
		del_ast(&node);
	return (node);
}
