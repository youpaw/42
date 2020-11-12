/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_get_bin_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:06:00 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:06:03 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <dirent.h>
#include "cc_str.h"

static char	*get_dir_path(const char **pathes, const char *bin)
{
	DIR				*dirp;
	struct dirent	*dire;

	if (pathes)
		while (*pathes)
		{
			if ((dirp = opendir(*pathes)))
			{
				while ((dire = readdir(dirp)))
					if (dire->d_type == DT_REG && !strcmp(bin, dire->d_name))
					{
						closedir(dirp);
						return (strdup(*pathes));
					}
				closedir(dirp);
			}
			pathes++;
		}
	return (NULL);
}

char		*hash_get_bin_path(const char *bin)
{
	char		**pathes;
	char		*path;
	char		*args[4];

	if (!bin || !(path = (char *)env_get_value("PATH")))
		return (NULL);
	pathes = strsplitcharset(path, ":");
	path = NULL;
	if ((args[0] = get_dir_path((const char **)pathes, bin)))
	{
		args[1] = "/";
		args[2] = (char *)bin;
		args[3] = NULL;
		path = strnjoin((const char **)args);
		free(args[0]);
	}
	strarr_del(pathes);
	free(pathes);
	return (path);
}
