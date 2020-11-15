/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_get_priority.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

int	calc_get_priority(t_calc_type type)
{
	if (type >= N_OPERATORS)
		return (10);
	else if (type < 2)
		return (1);
	else if (type > 1 && type < 5)
		return (2);
	else if (type > 4 && type < 7)
		return (3);
	else if (type > 6 && type < 11)
		return (4);
	else if (type > 10 && type < 13)
		return (5);
	else if (type == 13)
		return (6);
	else if (type == 14)
		return (7);
	return (0);
}
