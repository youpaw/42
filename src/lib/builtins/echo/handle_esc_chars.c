//
// Created by Halfhand Lorrine on 11/7/20.
//

#include "echo.h"

static char	*ft_handle_chr(char *str, int cnt)
{
	char *rchars;

	if (cnt == 3)
		return (NULL);
	rchars = "\\\a\b\0\f\n\r\t\v";
	*(++str) = rchars[cnt];
	return (str);
}


static int	ft_get_hex(char c)
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

static char		*ft_handle_hex(char *str)
{
	int		ch;
	int		tmp;

	str += 2;
	if ((ch = ft_get_hex(toupper(*str))) >= 0)
	{
		str++;
		if ((tmp = ft_get_hex(toupper(*str))) >= 0)
		{
			str++;
			ch *= 16;
			ch += tmp;
		}
		putchar(ch);
	}
	return (str);
}


static char	*ft_handle_oct(char *str)
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
			str = ft_handle_oct(str);
		else if (echars[cnt] == 'x')
			str = ft_handle_hex(str);
		else
			str = ft_handle_chr(str, cnt);
	}
	return (str);
}