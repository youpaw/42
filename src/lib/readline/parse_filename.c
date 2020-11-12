//
// Created by Maxon Gena on 11/11/20.
//

#include "readline.h"
#include "cc_mem.h"
#include "cc_str.h"

/*
** Splits fullname into path and name,
** and put them into filename[0] and [1] respectively
*/

static char		**fullname_with_delim(char *full, char **file, char *delimiter)
{
	if (!(delimiter[1]))
	{
		file[0] = strdup(full);
		file[1] = strdup("");
	}
	else if (delimiter == full)
	{
		file[0] = strdup("/");
		file[1] = strdup(full + 1);
	}
	else
	{
		*delimiter = '\0';
		file[0] = strdup(full);
		file[1] = strdup(delimiter + 1);
	}
	return (file);
}

char			**parse_filename(char *fullname)
{
	char *delimiter;
	char **filename;

	filename = xmalloc(sizeof(char*) * 2);
	fullname = strdup(fullname);
	delimiter = strrchr(fullname, '/');
	if (delimiter)
		filename = fullname_with_delim(fullname, filename, delimiter);
	else
	{
		filename[0] = strdup("./");
		filename[1] = strdup(fullname);
	}
	free(fullname);
	return (filename);
}
