//
// Created by Maxon Gena on 9/17/20.
//

#include "readline.h"
#include "cc_str.h"

char *find_same_part(t_list *files, char *filename)
{
	t_list *cur;
	unsigned int i;
	char same[1024];
	unsigned int len;

	if (!files)
		return (NULL);
	len = strlen(filename);
	if (files->next == files)
		return (strdup(&(files->content)[len]));
	i = 0;
	cur = files->next;
	while (((char*)cur->content)[i + len] == ((char*)files->content)[i + len])
	{
		same[i] = ((char*)files->content)[i + len];
		i++;
	}
	cur = cur->next;
	while (cur != files && *same)
	{
		i = 0;
		while (same[i] == ((char*)cur->content)[i + len])
			i++;
		same[i] = 0;
		cur = cur->next;
	}
	if (!*same)
		return (NULL);
	else
		return (strdup(same));
}
