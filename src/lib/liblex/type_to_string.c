#include "lexer.h"

const char *type_to_string(t_token_type t)
{
	static const char *token_types_map[N_TOKEN_TYPES] = {
			"word",
			"assignment name",
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
			"bang",
	};

	return (token_types_map[t]);
}