#include "cc_search.h"
#include "cc_mem.h"

t_avl				*avl_new_node(void *content)
{
	t_avl *node;

	node = (t_avl*)xmalloc(sizeof(t_avl));
	node->content = content;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return (node);
}
