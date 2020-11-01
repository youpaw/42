//
// Created by Halfhand Lorrine on 10/31/20.
//

#include "cc_graph.h"
#include "readline.h"
#include "env.h"
#include "cc.h"
#include <unistd.h>
#include <dirent.h>


static void		fill_builtins(t_graph *graph)
{
	static const char *builtins_names[N_BUILTINS] = {
			"exit", "set", "unset", "cd", "export", "hash", "echo",\
			"alias", "unalias"};
	int cnt;

	cnt = 0;
	while (cnt < N_BUILTINS)
	{
		graph_insert(graph, builtins_names[cnt]);
		cnt++;
	}
}

static void		path_join(char *bin_path, const char *path, const char *bin)
{
	bin_path[MAX_PATH] = '\0';
	strcpy(bin_path, path);
	strcat(bin_path, "/\0");
	strcat(bin_path, bin);
}


static void		fill_bins(t_graph *graph, const char *path)
{
	struct dirent	*entry;
	DIR				*dir;
	char 			bin_path[MAX_PATH + 1];

	if (!(dir = opendir(path)))
		return ;
	while ((entry = readdir(dir)) != NULL)
	{
		if (strcmp(entry->d_name, ".") > 0 &&  strcmp(entry->d_name, "..") > 0)
		{
			path_join(bin_path, path, entry->d_name);
			if ((access(bin_path, F_OK | X_OK)) == 0)
				graph_insert(graph, entry->d_name);
			bzero(bin_path, MAX_PATH);
		}
	}
	free(entry);
	closedir(dir);
}

static void 	get_bin_paths(t_graph *graph)
{
	const char	*full_path;
	char		**paths;
	int 		cnt;

	full_path = env_get_value("PATH");
	if (!full_path || !(paths = strsplitcharset(full_path, ":")))
		return ;
	cnt = 0;
	while (paths[cnt])
	{
		fill_bins(graph, paths[cnt]);
		cnt++;
	}
}

void	fill_complition_graph(t_graph *graph)
{
	graph_init(graph);
	fill_builtins(graph);
	get_bin_paths(graph);
}