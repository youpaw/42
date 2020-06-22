//
// Created by youpaw on 6/22/20.
//

#include "cc_avl.h"

t_avl_pair	*avl_get_pair(t_avl_obj *obj, const void *key)
{
	t_avl_tree *node;

	if ((node = avl_get(obj, key)))
		return (node->pair);
	return (NULL);
}