//
// Created by Halfhand Lorrine on 9/14/20.
//

#include "cd.h"

static int 	token_cpy(char *new_path, const char *token, int curr_i)
{
	int 	i;

	i = 0;
	while (token[i] && curr_i < MAX_PATH)
	{
		new_path[curr_i] = token[i];
		curr_i++;
		i++;
	}
	return (curr_i);
}

static char		*tokens_join(char **tokens, int len)
{
	char	*new_path;
	int 	cnt;
	int		curr_i;

	cnt = 0;
	curr_i = 0;
	new_path = memalloc(MAX_PATH + 1);
	while (cnt < len && curr_i < MAX_PATH)
	{
		new_path[curr_i] ='/';
		curr_i++;
		while (tokens[cnt] == NULL)
			cnt++;
		curr_i = token_cpy(new_path, tokens[cnt], curr_i);
		cnt++;
	}
	new_path[curr_i] = '\0';
	return(new_path);
}

static void tokens_handler(char **tokens, int len)
{
	int curr_e;
	int prev_e;

	curr_e = 0;
	prev_e = 0;
	while (curr_e < len)
	{
		if (strcmp(tokens[curr_e], "..") == 0)
		{
			tokens[curr_e] == NULL;
			prev_e = curr_e;
			if (prev_e != 0)
				tokens[prev_e] = NULL;
		}
		else if (strcmp(tokens[curr_e], ".") == 0)
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

	pwd = memalloc(MAX_PATH);
	if (path[0] != '/')
	{
		if (!(getcwd(pwd, MAX_PATH)))
			return (1);
		full_path = strjoin(pwd, path);
		*tokens = strsplitcharset(full_path, "/");
		free(full_path);
		free(pwd);
	}
	else
		*tokens = strsplit(path);
	return (0);
}

char	*path_canonization(char *path)
{
	char **tokens;
	char *new_path;
	int len;
	int cnt;

	cnt = 0;
	len = 0;
	if (!tokenizer(path, &tokens))
		return (NULL);
	while (tokens[len])
		len++;
	tokens_handler(tokens, len);
	tokens_join(tokens, len);
	new_path = tokens_join(tokens, len);
	while (cnt < len)
	{
		free(tokens[cnt]);
		cnt++;
	}
	free(*tokens);
	printf("%s", new_path);
	return (new_path);
}