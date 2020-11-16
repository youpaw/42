/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_state_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
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
