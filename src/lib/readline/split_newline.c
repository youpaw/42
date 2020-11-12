//
// Created by Maxon Gena on 11/8/20.
//

#include "readline.h"
#include "cc_str.h"
#include "cc_mem.h"
#include "cc_num.h"
static char **get_double_array(char *line)
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

//static char *fill_elem(char *line, size_t i, size_t *len)
//{
//	char *str;
//
//	if (!len)
//		str = strdup("");
//	else
//		str = strsub(line, i - *len, *len);
//	*len = 0;
//	return (str);
//}

char **split_newline(char *line)
{
	size_t i;
	size_t k;
	size_t len;
	char **res;

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
			if (!len)
				res[k] = strdup("");
			else
				res[k] = strsub(line, i - len, len);
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