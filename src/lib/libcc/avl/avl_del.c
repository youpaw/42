//
// Created by youpaw on 17.03.2020.
//

#include <stdlib.h>
#include "cc_avl.h"

static void walk_nodes(t_avl_tree *node, void (*del)(void *))
{
	if (!node)
		return ;
	walk_nodes(node->left, del);
	walk_nodes(node->right, del);
	if (del)
		del(node->pair);
	free(node->pair);
	free(node);
}

void	avl_del(t_avl_obj **obj)
{
	if (!obj || !*obj)
		return ;
	walk_nodes((*obj)->tree, (*obj)->del);
	free(*obj);
	*obj = NULL;
}
