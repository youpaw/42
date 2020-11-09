#include "lexer.h"

const char	*token_type_to_string(t_token_type t)
{
	static const char *token_types_map[N_TOKEN_TYPES] = {
			"and_if",
			"or_if",
			"double_less",
			"double_great",
			"less_and",
			"great_and",
			"and",
			"or",
			"less",
			"great",
			"semi",
			"newline",
			"bang",
			"io number",
			"assignment word",
			"command name",
			"word"
	};

	return (token_types_map[t]);
}
