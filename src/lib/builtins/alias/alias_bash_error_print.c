/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_bash_error_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias_builtins.h"

void		alias_bash_error_print(t_error_code er_code, const char *cmd,\
			const char *arg)
{
	char	*er_arr[3];

	er_arr[0] = (char *)cmd;
	er_arr[1] = NULL;
	if (arg != NULL)
		er_arr[1] = (char *)arg;
	er_arr[2] = NULL;
	error_print(er_code, (const char **)er_arr);
}
