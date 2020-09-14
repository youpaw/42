//
// Created by Halfhand Lorrine on 9/14/20.
//

#include "cc.h"



static int 	tokenizer(char *path, char ***tokens)
{
	char *full_path;
	char *pwd;

	if (path[0] != '/')
	{
		if (!(getcwd(pwd, 0)))
			return (1);
		full_path = strjoin(pwd, path);
		tokens = strsplit(full_path);
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

	if (!tokenizer(path, &tokens))
		return ;