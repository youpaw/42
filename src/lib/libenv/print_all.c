//
// Created by youpaw on 06.06.2020.
//

#include "env.h"
#include "string/cc_str.h"

static void	print_field(t_env *field)
{
	fdputs(field->name, 1);
	fdputs("=", 1);
	fdputs(field->val, 1);
}

void		print_all(void)
{
	avl_map_infix(g_env, (void (*)(void *)) &print_field);
}
