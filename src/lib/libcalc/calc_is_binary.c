/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_is_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:01:25 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:01:28 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

int	calc_is_binary(t_calc_type type)
{
	if (type > 1 && type < N_OPERATORS)
		return (1);
	return (0);
}
