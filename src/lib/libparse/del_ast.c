//
// Created by youpaw on 19.04.2020.
//

#include "parser.h"
#include <stdlib.h>

void				del_ast(t_ast **node)
{
	if (!node || !*node)
		return ;
	if ((*node)->left)
		del_ast(&((*node)->left));
	if ((*node)->right)
		del_ast(&((*node)->right));
	free(*node);
	*node = NULL;
}
