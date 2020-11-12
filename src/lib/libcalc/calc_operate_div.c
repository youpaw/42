/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_operate_div.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:01:54 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:01:57 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"
#include "error.h"

int	calc_operate_div(t_calc_eval *a, t_calc_eval *b)
{
	if (!a->val)
		return (E_ZERODIV);
	b->val = b->val / a->val;
	return (0);
}
