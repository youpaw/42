//
// Created by youpaw on 31.05.2020.
//

#include <glob.h>
#include "cc_char.h"
#include "env.h"

static int is_char_valid(char c)
{
	return (isalnum(c) || c == '_');
}
size_t get_valid_name_length(const char *name)
{
	size_t index;

	index = 0;
	if (isdigit(name[index]))
		return (0);
	while (is_char_valid(name[index]))
		index++;
	if (name[index] != '=')
		return (0);
	return (index);
}
