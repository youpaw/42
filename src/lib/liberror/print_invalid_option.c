//
// Created by Azzak Omega on 11/1/20.
//

#include "error.h"

int	print_invalid_option(const char *bin, char opt)
{
	char		str[2];
	const char	*args[2];

	str[0] = opt;
	str[1] = '\0';
	args[0] = bin;
	args[1] = str;
	error_print(E_INVALOPT, args);
	return (E_INVALOPT);
}
