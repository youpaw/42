//
// Created by youpaw on 17.03.2020.
//

#include <stdlib.h>
#include "cc_search.h"

void	avl_del(t_avl **avl, void (*del)(void *))
{
	if (!avl || !*avl)
		return ;
	avl_del(&((*avl)->left), del);
	avl_del(&((*avl)->right), del);
	del(&((*avl)->content));
	free(*avl);
	*avl = NULL;
}
