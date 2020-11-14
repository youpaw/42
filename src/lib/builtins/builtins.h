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

int		sh_cd(const char **av);
int		sh_set(const char **args);
int		sh_unset(const char **args);
int		sh_export(const char **av);
int		sh_hash(const char **av);
int		sh_echo(const char **av);
int		sh_alias(const char **av);
int		sh_unalias(const char **av);
int		sh_history(const char **av);

#endif
