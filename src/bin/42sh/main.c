#include "cc.h"
#include "lexer.h"
#include <stdio.h>

int main(int ac, char *av[], char *en[])
{
//	fdputs("Hello world!", 1);
//	printf("%lu", sizeof(t_list*));

	char *str = "ABDBDB=smth command smth;ls\n";
	t_tokens *tokens = lex_str(str, l_tok);
	print_tokens(tokens);
	return (0);
}
