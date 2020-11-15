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

typedef enum	e_error_code
{
	E_OK,
	E_NOENT,
	E_IO,
	E_BADF,
	E_NOMEM,
	E_ACCES,
	E_EXIST,
	E_NOTDIR,
	E_ISDIR,
	E_INVAL,
	E_FBIG,
	E_PIPE,
	E_NOINP,
	E_INCINP,
	E_EOF,
	E_BADSUBS,
	E_NOEVENT,
	E_UNEXPTOK,
	E_OPEXPEC,
	E_INVAOP,
	E_INVEXP,
	E_ZERODIV,
	E_INVIDENT,
	E_NUMARGREQ,
	E_TOOMANYARGS,
	E_INVALOPT,
	E_NOTFOUND,
	E_HOMENOTSET,
	E_OLDPWDNOTSET,
	E_NOSUCHJOB,
	E_NOJOBCONTROL,
	E_NAMETOOLONG,
	E_NOCMD,
	E_BADFD,
	E_AMBIG,
	E_ARGCNOTENOUGH,
	E_EXPAND,
	E_INVALALIAS
}				t_error_code;

/*
**E_NOENT,                        	No such file or directory*
**	E_IO,                          	Input/output error
**	E_BADF,                        	Bad file descriptor
**	E_NOMEM,                       	Cannot allocate memory
**	E_ACCES,                       	%: Permission denied
**	E_EXIST,                       	File exists
**	E_NOTDIR,                      	Not a directory
**	E_ISDIR,                        Is a directory
**	E_INVAL,                        Invalid argument
**	E_FBIG,                         File too large
**	E_PIPE,                         Broken pipe
**	E_NOINP,						Empty input
**	E_INCINP,						Incomplete input
**	E_EOF,							End of file from readline
**	E_BADSUBS,						Bad substitution
**	E_NOEVENT,						% Event not found
**	E_UNEXPTOK,						syntax error near unexpected token `%
**	E_OPEXPEC,						%: syntax error: operand expected\
** 										(error token is "%")
**	E_INVAOP,						%: syntax error: invalid arithmetic\
**										operator (error token is "%")
**	E_INVEXP,						%: syntax error in expression\
**										(error token is "%")
**	E_ZERODIV,						%: division by 0 (error token is "%")
**	E_INVIDENT,						%: `%': not a valid identifier
**	E_NUMARGREQ,					%: %: numeric argument required
**	E_TOOMANYARGS,					%: too many arguments
**	E_INVALOPT,						%: -%: invalid option
**	E_NOTFOUND,						%: %: not found
**	E_HOMENOTSET,					HOME not set
**	E_OLDPWDNOTSET,					OLDPWD not set
**	E_NOSUCHJOB,					%: %: no such job
**	E_NOJOBCONTROL,					%: no job control
**	E_NAMETOOLONG,					File name too long
**	E_NOCMD,						%: command not found
**	E_BADFD,						%: Bad file descriptor
**	E_AMBIG,						%: ambiguous redirect
**	E_ARGCNOTENOUGH,				%: not enough arguments
**	E_EXPAND						%: %
*/

void	error_print(t_error_code er_code, const char **args);
int		print_invalid_option(const char *bin, char opt);

#endif
