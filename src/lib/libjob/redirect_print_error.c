//
// Created by Fidelia Mallister on 11/4/20.
//

#include "error.h"

int			redirect_print_error(int errcode, const char *token)
{
	const char *args[2];

	args[0] = errcode == E_NOENT ? "" : token;
	args[1] = token;
	error_print(errcode, args);
	return (-1);
}
