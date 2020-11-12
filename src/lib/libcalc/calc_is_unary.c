/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_is_unary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:01:39 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:01:42 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

int	calc_is_unary(t_calc_type type)
{
	if (type < 2)
		return (1);
	return (0);
}
