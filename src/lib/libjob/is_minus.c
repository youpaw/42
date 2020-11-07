//
// Created by Fidelia Mallister on 11/4/20.
//

#include "parser.h"
#include "cc_str.h"

int 	is_minus(t_ast *leafs)
{
	return (leafs->left->left->token->raw && (strcmp(leafs->left->left->token->raw, "-") == 0));
}