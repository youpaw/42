//
// Created by youpaw on 6/24/20.
//

#include "env.h"
#include "memory/cc_mem.h"
#include "string/cc_str.h"

static char	*get_field(t_hash_pair *pair)
{
	t_env *field;

	field = pair->value;
	return (nstrjoin(3, pair->key, "=", field->val));
}

static size_t count_fields(void)
{
	size_t	ind;
	size_t	cnt;
	t_list	*tmp;

	ind = 0;
	cnt = 0;
	while (ind < g_exec_env->size)
	{
		tmp = g_exec_env->buckets[ind];
		while (tmp)
		{
			cnt++;
			tmp = tmp->next;
		}
		ind++;
	}
	return (cnt);
}

char 		**exec_env_2array(void)
{
	size_t cnt;
	char **arr;
	t_list *tmp;

	arr = xmalloc(sizeof(char *) * (count_fields() + 1));
	cnt = 0;
	while (cnt < g_exec_env->size)
	{
		tmp = g_exec_env->buckets[cnt];
		while (tmp)
		{
			arr[cnt] = get_field(tmp->content);
			tmp = tmp->next;
		}
		cnt++;
	}
	arr[cnt] = NULL;
	return (arr);
}
