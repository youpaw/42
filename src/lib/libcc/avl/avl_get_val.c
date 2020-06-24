//
// Created by youpaw on 6/22/20.
//

#include "cc_avl.h"

t_avl_pair	*avl_get_val(t_avl_obj *obj, const void *key)
{
	t_avl_pair *pair;

	if ((pair = avl_get_pair(obj, key)))
		return (pair->value);
	return (NULL);
}