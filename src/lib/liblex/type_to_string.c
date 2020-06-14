#include "lexer.h"

const char *type_to_string(t_token_type t)
{
	return (g_token_types_map[t]);
}