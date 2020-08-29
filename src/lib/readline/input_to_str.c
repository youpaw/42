//
// Created by Maxon Gena on 8/28/20.
//

#include "readline.h"

char	*input_to_str(t_input input)
{
	int i;
	char *string;
	char let[5];

	i = 0;
	bzero(let, 5);
	string = xmalloc(input.cursor_position * 4 * sizeof(char));
	while (i != input.cursor_position)
	{
		vec_get_at(let, input.line, i);
		strcat(string, let);
		i++;
	}
	return (string);

}
