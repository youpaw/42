/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_option.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int				print_invalid_option(const char *bin, char opt)
{
	char		str[2];
	const char	*args[2];

	str[0] = opt;
	str[1] = '\0';
	args[0] = bin;
	args[1] = str;
	error_print(E_INVALOPT, args);
	return (E_INVALOPT);
}
