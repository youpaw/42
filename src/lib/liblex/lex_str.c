//
// Created by youpaw on 04.05.2020.
//

#include "lexer.h"
#include "cc.h"

t_tokens	*lex_str(const char *string, t_stage stage)
{
	return (lex_str_sub(string, l_vld, strlen(string)));
}