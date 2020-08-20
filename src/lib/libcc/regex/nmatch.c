/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:35:38 by dbutterw          #+#    #+#             */
/*   Updated: 2020/08/20 19:30:12 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		nmatch(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	if (*s1 && *s2 == '*')
		return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
	if (!*s1 && *s2 == '*')
		return (nmatch(s1, s2 + 1));
	if (*s1 == *s2 && *s1 && *s2)
		return (nmatch(s1 + 1, s2 + 1));
	return (0);
}
