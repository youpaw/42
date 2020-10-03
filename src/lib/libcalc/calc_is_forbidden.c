//
// Created by youpaw on 9/28/20.
//

#include "cc_char.h"

int			calc_is_forbidden(char c)
{
	return (!(isalnum(c) || c == '*' || c == '+' || c == '-' || c == '/' ||
			  c == '%' || c == '(' || c == ')' || c == '<' || c == '=' ||
			  c == '>' || c == '!' || c == ' ' || c == '&' || c == '|'));
}