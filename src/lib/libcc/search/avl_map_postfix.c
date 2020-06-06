//
// Created by youpaw on 06.06.2020.
//

#include "cc_search.h"

void				avl_map_postfix(t_avl *avl, void (*f)(void *content))
{
	if (!avl)
		return ;
	avl_map_postfix(avl->left, f);
	avl_map_postfix(avl->right, f);
	f(avl->content);
}
