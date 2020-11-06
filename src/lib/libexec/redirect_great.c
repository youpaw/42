//
// Created by Fidelia Mallister on 11/4/20.
//
#include <fcntl.h>
#include "exec.h"
int 	redirect_great(t_ast *leafs, t_process *process, int is_double_great) // c
{
	int options;
	int from;
	int to;

	options = O_RDWR | O_CREAT | (is_double_great ? O_APPEND : O_TRUNC);
	from = redirect_parse_left_side(leafs, 1);
	to = redirect_parse_right_side(leafs, options, 0, 0);
	init_process_ioerr(process, from, to);
	return (0);
}