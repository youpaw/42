/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_usage_error_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:39:37 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 18:39:40 by hlorrine         ###   ########.fr       */
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
