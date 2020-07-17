//
// Created by youpaw on 6/24/20.
//

#include "env.h"
#include "memory/cc_mem.h"
#include "vector/cc_vec.h"
#include "string/cc_str.h"

static char	*get_field(t_hash_pair *pair)
{
	t_env *field;

	field = pair->value;
	return (nstrjoin(3, pair->key, "=", field->val));
}

char 		**exec_env_2array(void)
{
	size_t cnt;
	t_vec *vec;
	char **arr;
	t_list *tmp;

	vec = vec_new(g_exec_env->size, sizeof(char*));
	cnt = 0;
	while (cnt < g_exec_env->size)
	{
		tmp = g_exec_env->buckets[cnt];
		while (tmp)
		{
			vec_push(vec, get_field(tmp->content));
			tmp = tmp->next;
		}
		cnt++;
	}
	arr = vec->data;
	free(vec);
	return (arr);
}