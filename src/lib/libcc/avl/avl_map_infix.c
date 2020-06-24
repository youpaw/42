//
// Created by youpaw on 06.06.2020.
//

#include "cc_avl.h"

static void	walk_nodes(t_avl_tree *node, void (*f)(void *))
{
	if (!node)
		return ;
	walk_nodes(node->left, f);
	f(node->pair->value);
	walk_nodes(node->right, f);
}

void		avl_map_infix(t_avl_obj *obj, void (*f)(void *))
{
	if (!obj || !f)
		return ;
	walk_nodes(obj->tree, f);
}
