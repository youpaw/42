//
// Created by Darth Butterwell on 10/28/20.
//

#include "env.h"
#include "cc_str.h"

void			expand_exit_code(char **str)
{
	free(*str);
	*str = itoa(g_exit_code);
}
