/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pwd.h>
#include "env.h"
#include "cc_str.h"

static int			replace(char **str, const char *value)
{
	char	*tmp;

	if (!value)
		return (1);
	tmp = strdup(value);
	free(*str);
	*str = tmp;
	return (0);
}

static const char	*get_default_homedir(void)
{
	struct passwd	*pw;
	const char		*homedir;

	homedir = env_get_value("HOME");
	pw = getpwuid(getuid());
	if (!homedir && pw)
		homedir = pw->pw_dir;
	return (homedir);
}

int					expand_tilda(char **str)
{
	if (!strcmp(*str, "~"))
		return (replace(str, get_default_homedir()));
	else if (!strcmp(*str, "~+"))
		return (replace(str, env_get_value("PWD")));
	else if (!strcmp(*str, "~-"))
		return (replace(str, env_get_value("OLDPWD")));
	else
		return (1);
}
