//
// Created by Halfhand Lorrine on 9/14/20.
//

#include "cd.h"

static void		tokens_join(char **tokens, int len)
{
	char	*new_path;
	int 	cnt;
	int		i;

	cnt = 0;
	i = 0;
	new_path = xmalloc(PATH_LEN + 1);
	bzero(new_path, PATH_LEN);
	while (cnt < len)
	{
		new_path[i] ='/';

	}

}

static int 		get_path_len(char **tokens, int len)
{
	int		i;
	int		path_len;

	i = 0;
	path_len = 0;
	while (i < len)
	{
		if (tokens[i] != NULL)
		{
			path_len++;
			path_len += (strlen(tokens[i]) + 1);
		}
		i++;
	}
	return (path_len);
}

static void tokens_handler(char **tokens, int len)
{
	int curr_e;
	int prev_e;

	curr_e = 0;
	prev_e = 0;
	while (curr_e < len)
	{
		if (strcmp(tokens[curr_e], ".."))
		{
			tokens[curr_e] == NULL;
			prev_e = curr_e;
			if (prev_e != 0)
				tokens[prev_e] = NULL;
		}
		else if (strcmp(tokens[curr_e], "."))
		{
			tokens[curr_e] == NULL;
			prev_e = curr_e;
		}
		curr_e++;
	}
}

static int 	tokenizer(char *path, char ***tokens)
{
	char *full_path;
	char *pwd;

	pwd = NULL;
	if (path[0] != '/')
	{
		if (!(getcwd(pwd, 0)))
			return (1);
		full_path = strjoin(pwd, path);
		*tokens = strsplit(full_path);
		free(full_path);
		free(pwd);
	}
	else
		*tokens = strsplit(path);
	return (0);
}

void 	path_canonization(char *path)
{
	char **tokens;
	int len;
	int new_path_len;

	len = 0;
	if (!tokenizer(path, &tokens))
		return ;
	while (tokens[len])
		len++;
	tokens_handler(tokens, len);
	tokens_join(tokens, len);
}