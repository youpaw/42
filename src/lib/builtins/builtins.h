/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
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
