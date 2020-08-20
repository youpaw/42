//
// Created by youpaw on 02.06.2020.
//

#include "cc_avl.h"
#include "math/cc_math.h"

static t_avl_tree		*right_rotate(t_avl_tree *y)
{
	t_avl_tree *x;
	t_avl_tree *t;

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

static t_avl_tree		*left_rotate(t_avl_tree *x)
{
	t_avl_tree *y;
	t_avl_tree *t;

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

t_avl_tree		*avl_balance(t_avl_tree *node, int params, \
int (*cmp)(const void *, const void *, int))
{
	int balance;

	if (!node)
		return (node);
	balance = avl_get_height(node->left) - avl_get_height(node->right);
	if (balance > 1 && cmp(node->left->pair->key, node->pair->key, params) < 0)
		return (right_rotate(node));
	if (balance < -1 && \
	        cmp( node->right->pair->key, node->pair->key, params) > 0)
		return (left_rotate(node));
	if (balance > 1 && cmp(node->left->pair->key, node->pair->key, params) > 0)
	{
		node->left = left_rotate(node->left);
		return (right_rotate(node));
	}
	if (balance < -1 && \
		cmp(node->right->pair->key, node->pair->key, params) < 0)
	{
		node->right = right_rotate(node->right);
		return (left_rotate(node));
	}
	return (node);
}
