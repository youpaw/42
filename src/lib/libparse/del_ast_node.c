//
// Created by youpaw on 19.04.2020.
//

#include "parser.h"
#include <stdlib.h>

void 				del_ast_node(t_ast **node)
{
	if (!node || !*node)
		return ;
	if ((*node)->left)
		del_ast_node(&((*node)->left));
	if ((*node)->right)
		del_ast_node(&((*node)->right));
	free(*node);
	*node = NULL;
}