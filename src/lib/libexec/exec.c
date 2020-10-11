//
// Created by youpaw on 26.04.2020.
//

#include "exec.h"

void exec(t_ast *ast, t_tokens *tokens)
{
	tokens->index = 0;
	exec_complete_cmd(ast, NULL);
}
