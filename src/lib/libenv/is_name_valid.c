//
// Created by Darth Butterwell on 8/23/20.
//

#include "env.h"

size_t	is_name_valid(const char *field)
{
	size_t index;

	if (!field || !*field)
		return (0);
	index = 0;
	while (is_char_valid(field[index]))
		index++;
	if (field[index] != '=')
		return (0);
	return (index);
}