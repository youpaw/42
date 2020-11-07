//
// Created by Halfhand Lorrine on 11/7/20.
//

#include "echo.h"

static char	*handle_chr(char *str, int cnt)
{
	char *rchars;

	if (cnt == 3)
		return (NULL);
	rchars = "\\\a\b\0\f\n\r\t\v";
	putchar(rchars[cnt]);
	if ((str + 1) && (str + 2))
		str += 2;
	return (str);
}


static int	get_hex(char c)
{
	int		cnt;
	char	*set;

	cnt = 0;
	set = "0123456789ABCDEF";
	while (set[cnt] && set[cnt] != c)
		cnt++;
	if (!set[cnt])
		return (-1);
	return (cnt);
}

static char		*handle_hex(char *str)
{
	int		ch;
	int		tmp;

	str += 2;
	if ((ch = get_hex(toupper(*str))) >= 0)
	{
		str++;
		if ((tmp = get_hex(toupper(*str))) >= 0)
		{
			str++;
			ch *= 16;
			ch += tmp;
		}
		putchar(ch);
	}
	return (str);
}


static char	*handle_oct(char *str)
{
	int ch;

	str += 2;
	if (*str >= '0' && *str < '8')
	{
		ch = *str - '0';
		str++;
		if (*str >= '0' && *str < '8')
		{
			ch *= 8;
			ch += *str - '0';
			str++;
		}
		putchar(ch);
	}
	else
		putchar('\0');
	return (str);
}


char	*handle_esc_chars(char *str)
{
	int		cnt;
	char	c;
	char	*echars;

	c = *(str + 1);
	cnt = 0;
	echars = "\\abcfnrtv0x";
	while (echars[cnt] && echars[cnt] != c)
		cnt++;
	if (echars[cnt])
	{
		if (echars[cnt] == '0')
			str = handle_oct(str);
		else if (echars[cnt] == 'x')
			str = handle_hex(str);
		else
			str = handle_chr(str, cnt);
	}
	else
	{
		putchar('\\');
		str++;
	}
	return (str);
}