//
// Created by Maxon Gena on 11/8/20.
//

#include "readline.h"
#include "cc_str.h"
#include "cc_mem.h"

static char	**get_double_array(const char *line)
{
	size_t i;
	size_t counter;

	i = 0;
	counter = 0;
	while (line[i])
	{
		if (line[i++] == '\n')
			counter++;
	}
	return (xmalloc(sizeof(char*) * (counter + 2)));
}

static char	*get_line(int i, int len, char *line)
{
	char *res;

	if (!len)
		res = strdup("");
	else
		res = strsub(line, i - len, len);
	return (res);
}

char		**split_newline(char *line)
{
	size_t	i;
	size_t	k;
	size_t	len;
	char	**res;

	i = 0;
	k = 0;
	len = 0;
	res = get_double_array(line);
	while (line[i])
	{
		if (line[i] != '\n')
			len++;
		else
		{
			res[k] = get_line(i, len, line);
			k++;
			len = 0;
		}
		i++;
	}
	if (len)
		res[k++] = strsub(line, i - len, len);
	res[k] = NULL;
	return (res);
}
