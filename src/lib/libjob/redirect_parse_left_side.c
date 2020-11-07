//
// Created by Fidelia Mallister on 11/4/20.
//

#include "jobs.h"
#include "cc_num.h"

int 	redirect_parse_left_side(t_ast *leafs, int default_value) // c
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