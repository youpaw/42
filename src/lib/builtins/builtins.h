/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:23:14 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 20:23:28 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int		cd(const char **av);
int		set(const char **args);
int		unset(const char **args);
int		export(const char **av);
int		hash(const char **av);
int		sh_echo(const char **av);
int		alias(const char **av);
int		unalias(const char **av);
int		history(const char **av);

#endif
