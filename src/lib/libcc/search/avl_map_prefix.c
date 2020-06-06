//
// Created by youpaw on 06.06.2020.
//

#include "cc_search.h"

void				avl_map_prefix(t_avl *avl, void (*f)(void *content))
{
	if (!avl)
		return ;
	f(avl->content);
	avl_map_prefix(avl->left, f);
	avl_map_prefix(avl->right, f);
}
