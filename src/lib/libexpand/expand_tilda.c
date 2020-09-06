//
// Created by Azzak Omega on 8/29/20.
//

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include "env.h"
#include "cc_str.h"

static int replace(char **str, const char *value)
{
	char *slash;
	char *tmp;

	if (!value)
		return (1);
	if ((slash = strchr(*str, '/')))
		tmp = strjoin(value, slash);
	else
		tmp = strdup(value);
	free(*str);
	*str = tmp;
	return (0);
}

static const char *get_user_homedir(const char *str)
{
	struct passwd	*pw;
	const char		*slash;
	char			*uname;
	size_t			uname_len;

	uname_len = strlen(str)	- 1;
	if ((slash = strchr(str, '/')))
		uname_len = slash - str - 1;
	if (!uname_len)
		return (NULL);
	uname = strsub(str, 1, uname_len);
	pw = getpwnam(uname);
	free(uname);
	if (pw)
		return (pw->pw_dir);
	return (NULL);
}

static const char * get_default_homedir()
{
	struct passwd *pw;
	const char *homedir;

	if (!(homedir = env_get_value("HOME")) && (pw = getpwuid(getuid())))
		homedir = pw->pw_dir;
	return (homedir);
}

int 	expand_tilda(char **str)
{
	if (**str != '~')
		return (1);
	if (!strcmp(*str, "~") || !strncmp(*str, "~/", 2))
		return (replace(str, get_default_homedir()));
	else if (!strcmp(*str, "~+") || !strncmp(*str, "~+/", 3))
		return (replace(str, env_get_value("PWD")));
	else if (!strcmp(*str, "~-") || !strncmp(*str, "~-/", 3))
		return (replace(str, env_get_value("OLDPWD")));
	else
		return (replace(str, get_user_homedir(*str)));
}
