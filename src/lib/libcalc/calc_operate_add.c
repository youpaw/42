/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_operate_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

int		calc_operate_add(t_calc_eval *a, t_calc_eval *b)
{
	b->val = b->val + a->val;
	return (0);
}
