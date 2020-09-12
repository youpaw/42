//
// Created by Darth Butterwell on 9/6/20.
//

#include "main.h"
#include "cc.h"
#include "lexer.h"
#include "parser.h"

//int main(int ac, const char *av[], const char *env[])
//{
//	int error;
//
//	if (!(error = main_init(av[0], av + 1, env)))
//		error = main_manager();
//	return (error);
//}

int main(int ac, const char *av[], const char *env[])
{
	t_tokens *tokens;
	t_ast *ast;
	char *str;

	str = strdup("ls 123>smw");
	tokens = lex_str(str, l_vld);
	puts("\n");
	print_tokens(tokens);
	ast = parse(tokens);
	puts("\n");
}
