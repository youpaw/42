/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:23:09 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 20:23:11 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

int		sh_history(const char **av)
{
	(void)av;
	hist_print();
	return (0);
}
