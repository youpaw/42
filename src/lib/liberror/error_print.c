//
// Created by Azzak Omega on 9/8/20.
//
#include "error.h"
#include "cc_str.h"

const char 	*g_error_msg[] = {
	"No such file or directory",
	"Input/output error",
	"Bad file descriptor",
	"Cannot allocate memory",
	"Permission denied",
	"File exists",
	"Not a directory",
	"Is a directory",
	"Invalid argument",
	"File too large",
	"Broken pipe",
	"syntax error near unexpected token `%'",
	"%: %: syntax error: operand expected (error token is \"%\")"
};

void 	error_print(t_error_code er_code, const char **args)
{
	fdputs("42sh: ", 2);
	while (*args)
	{
		fdputs(*args++, 2);
		fdputs(": ", 2);
	}
	fdputendl(g_error_msg[er_code], 2);
}