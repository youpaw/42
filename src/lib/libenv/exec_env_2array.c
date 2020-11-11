//
// Created by youpaw on 6/24/20.
//

#include "env.h"
#include "cc_mem.h"
#include "cc_str.h"

static char	*get_field(t_hash_pair *pair)
{
	const char *arr[4];

	arr[0] = pair->key;
	arr[1] = "=";
	arr[2] = pair->value;
	arr[3] = NULL;
	return (strnjoin(arr));
}

char 		**exec_env_2array(void)
{
	size_t cnt;
	size_t i_arr;
	char **arr;
	t_list *tmp;

	arr = xmalloc(sizeof(char *) * (hash_map_get_size(g_exec_env) + 1));
	cnt = 0;
	i_arr = 0;
	while (cnt < g_exec_env->buckets_size)
	{
		tmp = g_exec_env->buckets[cnt];
		while (tmp)
		{
			if (((t_hash_pair *)tmp->content)->value)
				arr[i_arr++] = get_field(tmp->content);
			tmp = tmp->next;
		}
		cnt++;
	}
	arr[i_arr] = NULL;
	return (arr);
}
