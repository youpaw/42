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
# define ECHO_H

# define ECHO_N_FLAG 00000001
# define ECHO_E_LC_FLAG 00000010
# define ECHO_E_UPC_FLAG 00000100

# include "builtins.h"
# include "optparse.h"

char		*handle_esc_chars(char *str);

#endif
