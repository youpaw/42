//
// Created by youpaw on 6/21/20.
//

#ifndef CC_HASH_MAP_H
#define CC_HASH_MAP_H
#include "list/cc_lst.h"

struct s_hash_pair{
	void	*key;
	void	*value;
};

typedef struct s_hash_pair	t_hash_pair;

struct s_hash_table{
	t_list	**buckets;
	size_t	size;
	size_t	(*hasher)(const void *);
	int		(*cmp)(const void *, const void *);
	void 	(*del)(t_hash_pair *);
};

typedef struct s_hash_table	t_hash_table;

t_hash_table 	*hash_map_new(size_t n_buckets, \
	size_t (*hasher)(const void *), \
	int (*cmp)(const void *, const void *), \
	void 	(*del)(t_hash_pair *));
int				hash_map_insert(t_hash_table *table, t_hash_pair *pair);
t_list 			*hash_map_get(t_hash_table *table, const void *key);
t_hash_pair 	*hash_map_get_pair(t_hash_table *table, const void *key);
void 			*hash_map_get_val(t_hash_table *table, const void *key);
int 			hash_map_del_one(t_hash_table *table, const void *key);
void 			hash_map_del(t_hash_table **table);
void 			hash_map_iter_pair(t_hash_table *table, void (*f)(const t_hash_pair *pair));
void 			hash_map_iter(t_hash_table *table, void (*f)(void *value));

#endif //CC_HASH_MAP_H
