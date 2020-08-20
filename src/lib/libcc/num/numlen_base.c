//
// Created by youpaw on 30.03.2020.
//

#include <zconf.h>

int numlen_base(ssize_t num, int base)
{
	int lng;

	if (base < 2)
		return (0);
	lng = 1;
	while (num >= base || num <= (-base))
	{
		num /= base;
		lng++;
	}
	return (lng);
}