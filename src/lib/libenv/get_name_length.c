//
// Created by youpaw on 31.05.2020.
//

#include <glob.h>
#include "cc_char.h"

size_t get_name_length(const char *field)
{
	size_t index;

	index = 0;
	if (isdigit(field[index]))
		return (1);
	while (is_char_valid(field[index]))
		index++;
	return (index);
}
