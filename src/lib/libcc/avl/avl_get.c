//
// Created by youpaw on 02.06.2020.
//

#include "cc_avl.h"

t_avl_tree	*walk_nodes(const void *key, t_avl_tree *node, int params, \
	int (*cmp)(const void *, const void *, int))
{
	int cmp_val;

	if (!node)
		return (NULL);
	cmp_val = cmp(key, node->pair->key, params);
	if (cmp_val < 0)
		return (walk_nodes(key, node->left, params, cmp));
	else if (cmp_val > 0)
		return (walk_nodes(key, node->right, params, cmp));
	return (node);
}

t_avl_tree	*avl_get(t_avl_obj *obj, const void *key)
{
	if (!obj || !obj->tree || !key)
		return (NULL);
	return (walk_nodes(key, obj->tree, obj->params, obj->cmp));
}