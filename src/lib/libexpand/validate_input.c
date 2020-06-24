//
// Created by youpaw on 6/14/20.
//

#include "expand.h"

int 	validate_input(char **raw)
{
	return (expand_raw(raw, &validate_input_handler));
}