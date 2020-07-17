//
// Created by youpaw on 06.06.2020.
//

#include <zconf.h>
#include "env.h"

const char 	*env_get_field_val(const char *name)
{
	t_env *field;

	field = env_get_field(name);
	if (field)
		return (field->val);
	return (NULL);
}
