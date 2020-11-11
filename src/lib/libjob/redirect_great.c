//
// Created by Fidelia Mallister on 11/4/20.
//

#include <fcntl.h>
#include "jobs.h"

int		redirect_great(t_ast *leafs, t_process *process, int is_double_great)
{
	int options;
	int from;
	int to;

	options = O_RDWR | O_CREAT | (is_double_great ? O_APPEND : O_TRUNC);
	from = redirect_parse_left_side(leafs, 1);
	to = redirect_parse_right_side(leafs->left->left->token, options, 0, 0);
	redirect_init_process_file(process, from, to);
	puts("PPizda\n\n");
	return (0);
}
