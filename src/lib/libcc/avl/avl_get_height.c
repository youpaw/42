#include "cc_avl.h"

int 			avl_get_height(t_avl_tree *node)
{
	if (!node)
		return (0);
	return (node->height);
}
