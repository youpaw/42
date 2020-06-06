//
// Created by youpaw on 02.06.2020.
//

#include <stdlib.h>
#include "cc_search.h"
#include "math/cc_math.h"

static t_avl		*merge_childs(t_avl *avl, void *params, \
int (*cmp)(const void *, const void *, void *))
{
	if (!avl->left && !avl->right)
		return (NULL);
	else if (avl->left && !avl->right)
		return (avl->left);
	else if (!avl->left)
		return (avl->right);
	return (avl_insert(avl->right, avl->left, params, cmp));
}

static t_avl 		*del_node(t_avl *avl, const void *content, void *params, \
int (*cmp)(const void *, const void *, void *))
{
	int		cmp_val;

	cmp_val = cmp(content, avl->content, params);
	if (cmp_val < 0)
		avl->left = del_node(avl->left, content, params, cmp);
	else if (cmp_val > 0)
		avl->right = del_node(avl->right, content, params, cmp);
	else
		return (merge_childs(avl, params, cmp));
	avl->height = (int)max(avl_get_height(avl->left), \
    avl_get_height(avl->right)) + 1;
	return (avl_balance(avl, params, cmp));
}

void				*avl_pop(t_avl **avl, const void *content, void *params, \
int (*cmp)(const void *, const void *, void *))
{
	void	*pop_content;
	t_avl	*pop_node;

	if (!(pop_node = avl_get_node(*avl, content, params, cmp)))
		return (NULL);
	pop_content = pop_node->content;
	*avl = del_node(*avl, content, params, cmp);
	free(pop_node);
	return (pop_content);
}