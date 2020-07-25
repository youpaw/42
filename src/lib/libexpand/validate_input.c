//
// Created by youpaw on 6/14/20.
//

#include "expand.h"

int 	expand_input(char **raw)
{
	return (expand_raw(raw, &expand_input_handler, NULL));
}