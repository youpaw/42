#include "cc_search.h"

int 			avl_get_height(t_avl *node)
{
	if (!node)
		return (0);
	return (node->height);
}
