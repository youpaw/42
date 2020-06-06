#include "cc_search.h"
#include "cc_math.h"

t_avl				*avl_insert(t_avl *node, t_avl *new, void *params, \
int (*cmp)(const void *, const void *, void *))
{
	int cmp_val;

	if (!node)
		return (new);
	cmp_val = cmp(new->content, node->content, params);
	if (cmp_val < 0)
		node->left = avl_insert(node->left, new, params, cmp);
	else if (cmp_val > 0)
		node->right = avl_insert(node->right, new, params, cmp);
	else
		return (node);
	node->height = (int)max(avl_get_height(node->left), \
    avl_get_height(node->right)) + 1;
	return (avl_balance(node, params, cmp));
}
