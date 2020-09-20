//
// Created by Darth Butterwell on 9/19/20.
//

#include "parser.h"

const char *node_type_to_string(t_node_type type)
{
	static const char *node_types_map[N_NODE_TYPES] = {
			"complete_command",
			"list",
			"and_or",
			"pipe_sequence",
			"simple_command",
			"cmd_prefix",
			"cmd_suffix",
			"io_redirect",
			"io_file",
			"filename",
	};

	return (node_types_map[type]);
}