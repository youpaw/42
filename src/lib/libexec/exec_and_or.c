//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"
#include "cc.h"

int	exec_and_or(t_ast *ast)
{
	int code;

	code = exec_pipeline(ast->left);
	if (ast->right)
	{
		if ((!strcmp(ast->attr.raw, "&&") && !code) || \
		(!strcmp(ast->attr.raw, "||") && code))
			code = exec_and_or(ast->right);
	}
	return (code);
}