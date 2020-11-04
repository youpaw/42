//
// Created by Fidelia Mallister on 11/4/20.
//

#include "exec.h"

int 	l_less_and_redirect(t_ast *leafs, t_process *process) // c
{
	int from;
	int to;

	from = -1;
	to = -1;
	if (leafs->token)
	{
		if (leafs->token->type == l_io_number)
			to = atoi(leafs->token->raw);
	}
	else
		to = 0;
	return (0);
}