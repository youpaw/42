/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_io_here.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ast				*node_io_here(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_io_here);
	if (get_node_token(node, tokens) || !(node->left = node_here_end(tokens)))
		del_ast(&node);
	return (node);
}
