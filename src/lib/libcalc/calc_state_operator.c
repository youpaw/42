/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_state_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:03:04 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:03:07 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"
#include "error.h"

int	calc_state_operator(t_calc *calc)
{
	if (calc_get_operator(calc) && calc_get_number(calc))
		return (E_OPEXPEC);
	return (0);
}
