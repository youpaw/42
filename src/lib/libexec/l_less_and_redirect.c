//
// Created by Fidelia Mallister on 11/4/20.
//

#include "exec.h"

int 	l_less_and_redirect(t_ast *leafs, t_process *process) // c
{
	int from;
	int to;

	from = left_side(leafs, 0);
//	to = right_side(leafs, );
	if (leafs->token)
	{
		if (leafs->token->type == l_io_number)
			to = atoi(leafs->token->raw);
	}
	else
		to = 0;
	return (0);
}