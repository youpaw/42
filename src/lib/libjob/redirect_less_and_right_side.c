//
// Created by Fidelia Mallister on 11/8/20.
//

#include "jobs.h"
#include "cc_str.h"

int		redirect_less_and_right_side(t_ast *leafs)
{
	int to;

	to = -1;
	if (strisnum(leafs->left->left->token->raw))
	{
		to = atoi(leafs->left->left->token->raw);
		if (!is_standard_io(to))
			return (redirect_print_error(E_BADFD,
								leafs->left->left->token->raw));
	}
	else if (strcmp(leafs->left->left->token->raw, "-") == 0)
		return (-2);
	else
		return (redirect_print_error(E_AMBIG, leafs->left->left->token->raw));
	return (to);
}
