#include "lexer_internal.h"

int	is_operator(t_token_type t)
{
	return (t == l_and_if || t == l_or_if || t == l_double_semi || t == l_double_less || t == l_double_great || t == l_less_and || t == l_great_and || t == l_double_less_dash || t == l_clobber || t == l_less_great);
}