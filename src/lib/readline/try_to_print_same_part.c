//
// Created by Maxon Gena on 9/17/20.
//

#include "readline.h"
#include "cc_str.h"

void	inner_circle(t_list *files, t_list *cur, char *same, size_t len)
{
	int i;

	while (cur != files && *same)
	{
		i = 0;
		while (same[i] == ((char*)cur->content)[i + len])
			i++;
		same[i] = 0;
		cur = cur->next;
	}
}

char	*find_same_part(t_list *files, char *filename)
{
	unsigned int	i;
	unsigned int	len;
	t_list			*cur;
	char			same[1024];

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
	same[i] = 0;
	cur = cur->next;
	inner_circle(files, cur, same, len);
	if (!*same)
		return (NULL);
	else
		return (strdup(same));
}
