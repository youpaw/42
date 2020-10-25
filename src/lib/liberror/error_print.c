//
// Created by Azzak Omega on 9/8/20.
//

#include "cc_char.h"
#include "cc_str.h"
#include "error.h"

const char 	*g_error_msg[] = {
		NULL,
		"%: %: No such file or directory",
		"Input/output error",
		"Bad file descriptor",
		"Cannot allocate memory",
		"Permission denied",
		"File exists",
		"%: %: Not a directory",
		"%: %: Is a directory",
		"Invalid argument",
		"File too large",
		"Broken pipe",
		NULL,
		NULL,
		"%: bad substitution",
		"!%: event not found",
		"syntax error near unexpected token `%'",
		"%: %: syntax error: operand expected (error token is \"%\")",
		"%: %: not a valid identifier",
		"%: %: numeric argument required",
		"%: too many arguments",
		"%: %: invalid option",
  		"%: %: not found",
		"%: HOME not set",
		"%: OLDPWD not set",
		"%: %: File name too long",

};

void 	error_print(t_error_code er_code, const char **args)
{
	const char	*format;

	format = g_error_msg[er_code];
	fdputs("42sh: ", 2);
	while (*format)
	{
		if (*format != '%')
			fdputchar(*format, 2);
		else
			fdputs(*args++, 2);
		format++;
	}
	fdputchar('\n', 2);
}
