/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_get_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:01:20 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:01:22 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

int		calc_get_token(t_calc *calc)
{
	static int (*handlers[N_CALC_STATES])(t_calc *) = {
			&calc_state_operator, &calc_state_number
	};

	return (handlers[calc->state](calc));
}
