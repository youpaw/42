//
// Created by youpaw on 03.03.2020.
//

#ifndef CC_SEARCH_H
#define CC_SEARCH_H

typedef struct		s_avl
{
	void			*content;
	struct s_avl	*left;
	struct s_avl	*right;
	int				height;
}					t_avl;

t_avl				*avl_balance(t_avl *node, void *params, \
int (*cmp)(const void *, const void *, void *));

int 				avl_get_height(t_avl *node);

t_avl				*avl_new_node(void *content);

t_avl				*avl_get_node(t_avl *avl, const void *content, void *params, \
int (*cmp)(const void *, const void *, void *));

t_avl				*avl_insert(t_avl *node, t_avl *new, void *params, \
int (*cmp)(const void *, const void *, void *));

void				*avl_pop(t_avl **avl, const void *content, void *params, \
int (*cmp)(const void *, const void *, void *));

void				avl_map_prefix(t_avl *avl, void (*f)(void *content));

void				avl_map_infix(t_avl *avl, void (*f)(void *content));

void				avl_map_postfix(t_avl *avl, void (*f)(void *content));

void 				avl_del(t_avl **avl, void (*del)(void *));

#endif //CC_SEARCH_H
