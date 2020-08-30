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
	string = xmalloc((input.cursor_position * 4 * sizeof(char) + 1));
	bzero(string, (input.cursor_position * 4) + 1);
	while (i != input.cursor_position)
	{
		bzero(let, 5);
		vec_get_at(let, input.line, i);
		strcat(string, let);
		i++;
	}
	return (string);

}
