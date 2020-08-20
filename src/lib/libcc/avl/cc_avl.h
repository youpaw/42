//
// Created by youpaw on 03.03.2020.
//

#ifndef CC_AVL_H
#define CC_AVL_H

#include <stddef.h>

struct s_avl_pair{
	void	*key;
	void	*value;
};

struct				s_avl_tree
{
	struct s_avl_pair	*pair;
	struct s_avl_tree	*left;
	struct s_avl_tree	*right;
	int				height;
};

struct 				s_avl_obj
{
	int params;
	int (*cmp)(const void *, const void *, int);
	void (*del)(void *);
	struct s_avl_tree	*tree;
};

typedef struct s_avl_pair	t_avl_pair;
typedef struct s_avl_tree	t_avl_tree;
typedef struct s_avl_obj	t_avl_obj;

t_avl_obj 				*avl_new(int params, \
	int (*cmp)(const void *, const void *, int), \
	void (*del)(void *));

t_avl_tree				*avl_balance(t_avl_tree *node, int params, \
	int (*cmp)(const void *, const void *, int));
int 					avl_get_height(t_avl_tree *node);

t_avl_tree				*avl_new_node(t_avl_pair *pair);
t_avl_tree				*avl_insert(t_avl_obj *obj, t_avl_pair *pair);

t_avl_tree				*avl_get(t_avl_obj *obj, const void *key);
t_avl_pair 				*avl_get_pair(t_avl_obj *obj, const void *key);
void					*avl_get_val(t_avl_obj *obj, const void *key);

void					avl_map_prefix(t_avl_obj *obj, void (*f)(void *));
void					avl_map_infix(t_avl_obj *obj, void (*f)(void *));
void					avl_map_postfix(t_avl_obj *obj, void (*f)(void *));

int						avl_del_one(t_avl_obj *obj, const void *key);
void 					avl_del(t_avl_obj **obj);

#define AVL_OK 0
#define AVL_DNE AVL_OK + 1

#endif //CC_AVL_H
