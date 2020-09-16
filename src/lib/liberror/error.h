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

typedef enum	e_error_code
{
	E_OK,
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
	E_NOINP,						/* Empty input */
	E_INCINP,						/* Incomplete input */
	E_BADSUBS,						/* Bad substitution */
	E_NOEVENT,						/* Event not found */
	E_UNEXPTOK,						/* syntax error near unexpected token `%'*/
	E_OPEXPEC,						/* %: %: syntax error: operand expected (error token is \"%\") */
	E_INVIDENT,						/* %: `%': not a valid identifier*/
	E_NUMARGREQ,					/* %: %: numeric argument required*/
	E_TOOMANYARGS					/* %: too many arguments*/
}				t_error_code;

void 	error_print(t_error_code er_code, const char **args);

#endif
