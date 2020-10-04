//
// Created by youpaw on 9/24/20.
//

#include "cc_str.h"

int 	is_path(const char *str)
{
	if (*str == '/' || !strncmp(str, "./", 2) || !strncmp(str, "../", 3))
		return (1);
	return (0);
}