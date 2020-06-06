//
// Created by youpaw on 02.06.2020.
//

#include <zconf.h>
#include "cc_search.h"

t_avl	*avl_get_node(t_avl *avl, const void *content, void *params, \
int (*cmp)(const void *, const void *, void *))
{
	int cmp_val;

	if (!avl)
		return (NULL);
	cmp_val = cmp(content, avl->content, params);
	if (cmp_val < 0)
		return (avl_get_node(avl->left, content, params, cmp));
	else if (cmp_val > 0)
		return (avl_get_node(avl->right, content, params, cmp));
	return (avl);
}