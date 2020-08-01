//
// Created by youpaw on 6/14/20.
//

#include "expand.h"

static int handle_dollar(t_expand *expand)
{

}

int 	expand_input(char **raw)
{
	return (expand_raw(raw, &expand_input_handler, NULL));
}