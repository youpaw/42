//
// Created by Fidelia Mallister on 11/4/20.
//

#include "exec.h"
#include "cc_str.h"
#include <fcntl.h>
#include "error.h"

int 	right_side(t_ast *leafs, int open_options, int can_be_number, int is_maybe_minus) // c
{
	int right_side;

	right_side = -1;
	if (leafs->left->left->token)
	{
		if (leafs->left->left->token->raw)
		{
			if (can_be_number && is_valid_number(leafs->left->left->token->raw))
			{
				right_side = atoi(leafs->left->left->token->raw);
				if (!is_standard_io(right_side))
					return redirect_print_error(E_BADFD, leafs->left->left->token->raw);
				return (right_side);
			}
			else if (is_maybe_minus)
			{
				if (strcmp(leafs->left->left->token->raw, "-") == 0)
					return (-2);
			}
			if ((right_side = open(leafs->left->left->token->raw, open_options, 0644)) == -1)
				return (1);
		}
	}
	return (right_side);
}