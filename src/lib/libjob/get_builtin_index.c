/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_str.h"
#include "jobs.h"

int		get_builtin_index(const char *name)
{
	int					i;
	static const char	*builtins_names[N_BUILTINS] = {
			"exit", "set", "unset", "cd", "export", "hash",
			"echo", "alias", "unalias", "jobs", "fg", "bg",
			"history", "type"};

	i = -1;
	while (++i < N_BUILTINS)
		if (!strcmp(name, builtins_names[i]))
			return (i);
	return (-1);
}
