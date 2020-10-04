//
// Created by youpaw on 9/28/20.
//

#include "cc_char.h"

static int isspecial(char c)
{
	static const char *str = "*+_/%()<=>!&|";
	int index;

	index = 0;
	while (c != str[index])
		index++;
	if (str[index])
		return (1);
	return (0);
}

int			calc_is_forbidden(char c)
{
	return (!(isalnum(c) || isspecial(c)));
}