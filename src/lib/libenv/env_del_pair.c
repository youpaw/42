//
// Created by youpaw on 6/24/20.
//

#include "env.h"

void 		env_del_pair(t_hash_pair *pair)
{
	t_env *field;

	free(pair->key);
	field = pair->value;
	free(field->val);
	free(field);
}
