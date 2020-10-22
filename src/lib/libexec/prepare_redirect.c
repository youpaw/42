//
// Created by youpaw on 10/6/20.
//

#include "exec.h"
#include <stdio.h> // delete this
int 	prepare_redirect(t_ast *ast, t_process *process)
{
	size_t i;
	t_ast **redirects;

	if ((redirects = get_redirect_nodes(ast)) == NULL)
		return (0);
	//... WIP
	return (0);
}