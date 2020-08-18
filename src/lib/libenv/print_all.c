//
// Created by youpaw on 06.06.2020.
//

#include "env.h"
#include "string/cc_str.h"

static void	print_field(const t_hash_pair *pair)
{
	t_env *field;

	if ((field = pair->value))
	{
		fdputs(pair->key, 1);
		fdputs("=", 1);
		fdputs(field->val, 1);
	}
}

void		print_all(void)
{
	hash_map_iter_pair(g_env, &print_field);
}
