/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:38:41 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 18:38:48 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
#define ECHO_H

#include "builtins.h"
#include "cc.h"
#include "optparse.h"

#define ECHO_n_FLAG 00000001
#define ECHO_e_FLAG 00000010
#define ECHO_E_FLAG 00000100

typedef struct		s_echo
{
	char			first;
	char			second;
}					t_echo;

char		*handle_esc_chars(char *str);


#endif
