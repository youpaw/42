//
// Created by youpaw on 06.06.2020.
//

#include "env.h"
#include "string/cc_str.h"
#include "memory/cc_mem.h"

t_hash_table *g_exec_env;

static t_env	*cpy_field(t_env *field)
{
	t_env *cpy;

	cpy = xmalloc(sizeof(t_env));
	cpy->val = strdup(field->val);
	cpy->type = field->type;
	return (cpy);
}

static void 	cpy_pair(t_hash_pair *dst, t_hash_pair *src)
{
	dst->key = strdup(src->key);
	dst->value = cpy_field(src->value);
}

static t_list	*cpy_bucket(t_list *bucket)
{
	t_list *cpy;

	if (bucket)
	{
		cpy = lst_new(bucket->content, bucket->size);
		cpy_pair(cpy->content, bucket->content);
		cpy->next = cpy_bucket(bucket->next);
		return (cpy);
	}
	return (NULL);
}

void	exec_env_init(void)
{
	int cnt;

	cnt = 0;
	g_exec_env = hash_new(N_MAX_EXEC_ENV, \
    (size_t (*)(const void *)) &strhash, \
	(int (*)(const void *, const void *)) &strcmp, \
	&env_del_pair);
	while (cnt < g_env->size && cnt < g_exec_env->size)
	{
		g_exec_env->buckets[cnt] = cpy_bucket(g_env->buckets[cnt]);
		cnt++;
	}
}
