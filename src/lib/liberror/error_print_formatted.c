//
// Created by Azzak Omega on 9/8/20.
//

#include "cc_char.h"
#include "cc_str.h"
#include "error.h"

void 	error_print_formatted(t_error er_code, const char **args)
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
