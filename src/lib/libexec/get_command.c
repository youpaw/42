//
// Created by youpaw on 10/11/20.
//

#include "exec.h"

char *get_command(t_tokens *tokens, int async)
{
	t_vec *vec;

	vec = vec_new(EXEC_VEC_CAPACITY, sizeof(char *), NULL);

}