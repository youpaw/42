/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_doublequote_esc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_doublequote_esc(char c)
{
	static char	esc[] = "\"\\$";
	int			index;

	index = 0;
	while (esc[index] && esc[index] != c)
		index++;
	if (!esc[index])
		return (0);
	return (1);
}
