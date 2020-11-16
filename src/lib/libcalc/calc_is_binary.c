/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_is_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

int	calc_is_binary(t_calc_type type)
{
	if (type > 1 && type < N_OPERATORS)
		return (1);
	return (0);
}
