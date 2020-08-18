#include "cc_avl.h"
#include "memory/cc_mem.h"

t_avl_tree				*avl_new_node(t_avl_pair *pair)
{
	t_avl_tree *node;

	node = (t_avl_tree*)xmalloc(sizeof(t_avl_tree));
	node->pair = (t_avl_pair*)xmalloc(sizeof(t_avl_pair));
	memmove(node->pair, pair, sizeof(t_avl_pair));
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return (node);
}
