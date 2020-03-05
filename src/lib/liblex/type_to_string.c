#include "lexer_internal.h"

static char g_names[100][100];
static int g_initialized = 0;

void	init()
{
	strcpy(g_names[l_undefined], "undefined");
	strcpy(g_names[l_word], "word");
	strcpy(g_names[l_name], "name");
	strcpy(g_names[l_and_if], "and_if");
	strcpy(g_names[l_or_if], "or_if");
	strcpy(g_names[l_double_semi], "double_semi");
	strcpy(g_names[l_newline], "newline");
	strcpy(g_names[l_io_number], "io_number");
	strcpy(g_names[l_double_less], "double_less");
	strcpy(g_names[l_double_great], "double_great");
	strcpy(g_names[l_less_and], "less_and");
	strcpy(g_names[l_great_and], "great_and");
	strcpy(g_names[l_less_great], "less_great");
	strcpy(g_names[l_double_less_dash], "double_less_dash");
	strcpy(g_names[l_clobber], "clobber");
	strcpy(g_names[l_left_brace], "left_brace");
	strcpy(g_names[l_right_brace], "right_brace");
	strcpy(g_names[l_bang], "bang");
	strcpy(g_names[l_token], "token");
		
	g_initialized = 1;
}

char *type_to_string(t_token_type t)
{
	if (!g_initialized)
	{
		init();
	}
	return (g_names[t]);
}