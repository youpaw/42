/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_error_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

int	cd_error_print(t_error_code er_code, const char *arg)
{
	char	*er_arr[3];

	if (er_code == E_NOENT)
		er_arr[0] = "cd: ";
	else
		er_arr[0] = "cd";
	er_arr[1] = NULL;
	er_arr[2] = NULL;
	if (arg != NULL)
		er_arr[1] = (char *)arg;
	error_print(er_code, (const char **)er_arr);
	return (1);
}
