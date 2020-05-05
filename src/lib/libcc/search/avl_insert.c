#include "cc_search.h"
#include "cc_math.h"

static t_avl		*right_rotate(t_avl *y)
{
	t_avl *x;
	t_avl *t;

	x = y->left;
	t = x->right;
	x->right = y;
	y->left = t;
	y->height = (int)max(avl_get_height(x->right), \
	avl_get_height(x->left)) + 1;
	y->height = (int)max(avl_get_height(y->right), \
	avl_get_height(y->left)) + 1;
	return (x);
}

static t_avl		*left_rotate(t_avl *x)
{
	t_avl *y;
	t_avl *t;

	y = x->right;
	t = y->left;
	y->left = x;
	x->right = t;
	y->height = (int)max(avl_get_height(x->right), \
	avl_get_height(x->left)) + 1;
	y->height = (int)max(avl_get_height(y->right), \
	avl_get_height(y->left)) + 1;
	return (y);
}

static t_avl		*balance(t_avl *node, void *params, \
int (*cmp)(const void *, const void *, void *))
{
	int balance;

	if (!node)
		return (node);
	balance = avl_get_height(node->left) - avl_get_height(node->right);
	if (balance > 1 && cmp(node->left->content, node->content, params) < 0)
		return (right_rotate(node));
	if (balance < -1 && cmp( node->right->content, node->content, params) > 0)
		return (left_rotate(node));
	if (balance > 1 && cmp(node->left->content, node->content, params) > 0)
	{
		node->left = left_rotate(node->left);
		return (right_rotate(node));
	}
	if (balance < -1 && cmp(node->right->content, node->content, params) < 0)
	{
		node->right = right_rotate(node->right);
		return (left_rotate(node));
	}
	return (node);
}

t_avl				*avl_insert(t_avl *node, t_avl *new, void *params, \
int (*cmp)(const void *, const void *, void *))
{
	if (!node)
		return (new);
	if (cmp(new->content, node->content, params) < 0)
		node->left = avl_insert(node->left, new, params, cmp);
	else
		node->right = avl_insert(node->right, new, params, cmp);
	node->height = (int) max(avl_get_height(node->left), \
    avl_get_height(node->right)) + 1;
	return (balance(node, params, cmp));
}
