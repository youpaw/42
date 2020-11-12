/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_state_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:02:56 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:02:59 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"
#include "error.h"

int	calc_state_number(t_calc *calc)
{
	if (calc_get_operator(calc))
	{
		if (calc_is_forbidden(calc->raw[calc->index]))
			return (E_INVAOP);
		return (E_INVEXP);
	}
	return (0);
}
