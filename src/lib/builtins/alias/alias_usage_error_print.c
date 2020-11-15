/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_usage_error_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias_builtins.h"
#include "cc_str.h"

void	alias_usage_error_print(const char *cmd, int *er_code)
{
	*er_code = 2;
	puts(cmd);
	puts(": usage: ");
	puts(cmd);
	if (strcmp(cmd, "alias") == 0)
		puts(" [-p]");
	else
		puts(" [-a]");
	putendl(" name [name ...]");
}
