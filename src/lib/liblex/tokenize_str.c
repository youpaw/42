//
// Created by youpaw on 04.05.2020.
//

#include "lexer.h"
#include "cc.h"

t_tokens	*tokenize_str(const char *string)
{
	return (tokenize_str_sub(string, strlen(string)));
}