//
// Created by youpaw on 6/21/20.
//

#include <stddef.h>
#include "cc_avl.h"
#include "memory/cc_mem.h"

t_avl_obj 				*avl_new(int params, \
	int (*cmp)(const void *, const void *, int), \
	void (*del)(void *))
{
	t_avl_obj *obj;

	if (!cmp || !del)
		return (NULL);
	obj = xmalloc(sizeof(t_avl_obj));
	obj->params = params;
	obj->cmp = cmp;
	obj->del = del;
	obj->tree = NULL;
	return (obj);
}