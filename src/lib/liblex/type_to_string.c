#include "lexer.h"

const char *g_token_types_map[N_TOKEN_TYPES] = {
		"undefined",
		"word",
		"name",
		"and_if",
		"or_if",
		"double_semi",
		"newline",
		"io_number",
		"double_less",
		"double_great",
		"less_and",
		"great_and",
		"less_great",
		"double_less_dash",
		"clobber",
		"left_brace",
		"right_brace",
		"bang",
		"token"
};

const char *type_to_string(t_token_type t)
{
	return (g_token_types_map[t]);
}