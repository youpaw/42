//
// Created by Fidelia Mallister on 11/4/20.
//

#include "exec.h"
#include <unistd.h>
#include "cc_str.h"
#include "cc_char.h"

int is_standard_io(int fd)
{
	return (fd == STDIN_FILENO || fd == STDERR_FILENO || fd == STDOUT_FILENO);
}

int 	is_minus(t_ast *leafs)
{
	return (leafs->left->left->token->raw && (strcmp(leafs->left->left->token->raw, "-") == 0));
}