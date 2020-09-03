//
// Created by Maxon Gena on 8/28/20.
//

#include "readline.h"

char *input_to_str(t_vec *input, int len)
{
	int i;
	char *string;
	char let[5];

	i = 0;
	string = xmalloc((len* 4 * sizeof(char) + 1));
	bzero(string, (len * 4) + 1);
	while (i != len)
	{
		bzero(let, 5);
		vec_get_at(let, input, i);
		strcat(string, let);
		i++;
	}
	return (string);

}
