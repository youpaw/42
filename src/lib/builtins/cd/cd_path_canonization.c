//
// Created by Halfhand Lorrine on 9/14/20.
//

#include "cd.h"

static char		*fill_empty_path(const char *path)
{
	char		*new_path;
	const char *oldpwd;
	int 		len;

	oldpwd = env_get_value("OLDPWD");
	len = strlen(path) - 1;
	while (len > 0 && path[len] == '/')
		len--;
	if (len == 0 && strcmp(path, "//") != 0)
		new_path = strdup("/");
	else if ((strcmp(path, "-")) == 0)
		new_path = strdup(oldpwd);
	else
		new_path = strdup(path);
	return (new_path);
}

static char		*tokens_join(char ***tokens, int len)
{
	char	*new_path;
	int 	cnt;

	cnt = 0;
	new_path = memalloc(MAX_PATH + 1);
	while (cnt < len && cnt < MAX_PATH)
	{
		if ((*tokens)[cnt] != NULL)
		{
			strcat(new_path, "/\0");
			strcat(new_path, (*tokens)[cnt]);
		}
		cnt++;
	}
	cnt = 0;
	while (cnt < len)
	{
		free((*tokens)[cnt]);
		cnt++;
	}
	free(*tokens);
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
			tokens[curr_e] = NULL;
			tokens[prev_e] = NULL;
		}
		else if (strcmp(tokens[curr_e], ".") == 0)
			tokens[curr_e] = NULL;
		prev_e = curr_e;
		while (tokens[prev_e] == NULL && prev_e >= 0)
				prev_e--;
		curr_e++;
	}
}

static int 	tokenizer(const char *path, char ***tokens)
{
	char *full_path;
	char *pwd;
	const char *oldpwd;

	pwd = memalloc(MAX_PATH + 1);
	if (strcmp(path, "-") == 0)
	{
		oldpwd = env_get_value("OLDPWD");
		*tokens = strsplitcharset(oldpwd, "/");
	}
	else if (path[0] != '/')
	{
		if (!(getcwd(pwd, MAX_PATH + 1)))
			return (1);
		pwd[strlen(pwd)] = '/';
		full_path = strjoin(pwd, path);
		*tokens = strsplitcharset(full_path, "/");
		free(full_path);
		free(pwd);
	}
	else
		*tokens = strsplitcharset(path, "/");
	return (0);
}

char	*cd_path_canonization(const char *path)
{
	char **tokens;
	char *new_path;
	int len;

	len = 0;
	new_path = NULL;
	if (!path || !*path || tokenizer(path, &tokens))
		return (new_path);
	while (tokens[len])
		len++;
	tokens_handler(tokens, len);
	if (!tokens || !(*tokens))
	{
		new_path = fill_empty_path(path);
		return (new_path);
	}
	new_path = tokens_join(&tokens, len);
	return (new_path);
}