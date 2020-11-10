
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
	E_ARGCNOTENOUGH
}				t_error_code;

void			error_print(t_error_code er_code, const char **args);
int				print_invalid_option(const char *bin, char opt);

#endif
