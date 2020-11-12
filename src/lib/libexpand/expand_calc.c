//
// Created by youpaw on 10/3/20.
//

#include "calc.h"
#include "cc_regex.h"
#include "cc_str.h"

int			expand_calc(char **str)
{
	const char	*arg[4];
	char		*tmp;

	if (!match(*str, "(*)"))
	{
		arg[0] = "(";
		arg[1] = *str;
		arg[2] = ")";
		arg[3] = NULL;
		tmp = strnjoin(arg);
		free(*str);
		*str = tmp;
	}
	return (calc(str));
}
