//
// Created by youpaw on 06.06.2020.
//

#include "cc_search.h"

void				avl_map_infix(t_avl *avl, void (*f)(void *content))
{
	if (!avl)
		return ;
	avl_map_infix(avl->left, f);
	f(avl->content);
	avl_map_infix(avl->right, f);
}
