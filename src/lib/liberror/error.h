/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:02:56 by azomega           #+#    #+#             */
/*   Updated: 2020/09/08 16:03:02 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
//# define ERROR_COUNT 11

extern const char	*g_error_msg[];

typedef enum	e_error
{
/*
**	Standard errors
*/
	E_NOENT,                        /* No such file or directory */
	E_IO,                           /* Input/output error */
	E_BADF,                         /* Bad file descriptor */
	E_NOMEM,                        /* Cannot allocate memory */
	E_ACCES,                        /* Permission denied */
	E_EXIST,                        /* File exists */
	E_NOTDIR,                       /* Not a directory */
	E_ISDIR,                        /* Is a directory */
	E_INVAL,                        /* Invalid argument */
	E_FBIG,                         /* File too large */
	E_PIPE,                         /* Broken pipe */
/*
**	Formatted errors start from here
*/
	EF_SYN_UNEXPTOK,						/* syntax error near unexpected token `%'*/
	EF_SYN_OPEXPEC					/* %: %: syntax error: operand expected (error token is \"%\") */
}				t_error;

void 	error_print(t_error er_code, const char **args);
void 	error_print_formatted(t_error er_code, const char **args);

#endif
