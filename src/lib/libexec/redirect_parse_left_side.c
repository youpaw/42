//
// Created by Fidelia Mallister on 11/4/20.
//

#include "exec.h"

int 	left_side(t_ast *leafs, int default_value) // c
{
	int left;

	left = default_value;
	if (leafs->token)
	{
		if (leafs->token->type == l_io_number)
		{
			if (leafs->token->raw)
				left = atoi(leafs->token->raw);
		}
	}
	return (left);
}