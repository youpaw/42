/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 01:13:55 by dbutterw          #+#    #+#             */
/*   Updated: 2020/08/20 19:30:12 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	strclr(char *s)
{
	if (!s)
		return ;
	while (*s)
		*s++ = '\0';
}
