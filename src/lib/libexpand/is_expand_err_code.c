//
// Created by Azzak Omega on 11/12/20.
//

int		is_expand_err_code(const char *str)
{
	if (!str || !*str)
		return (1);
	while (*str == '?')
		str++;
	if (!*str)
		return (0);
	return (1);
}
