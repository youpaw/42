//
// Created by Darth Butterwell on 8/28/20.
//

#include "cc_char.h"

int is_number(const char *str)
{
	if (!str || !*str)
		return (0);
	while (isdigit(*str))
		str++;
	if (!*str)
		return (1);
	return (0);
}
