//
// Created by Maxon Gena on 8/29/20.
//

#include "readline.h"
#include "cc_char.h"

/*
 * Function converted utf-8 sequence in decimal.
 */

static uint32_t to_cp(const char chr[4])
{
	utf_t *utf[6];
	int bytes;
	int shift;
	int i;

	utf[0] = &(utf_t){0b00111111, 0b10000000, 0,       0,        6    };
	utf[1] = &(utf_t){0b01111111, 0b00000000, 0000,    0177,     7    };
	utf[2] = &(utf_t){0b00011111, 0b11000000, 0200,    03777,    5    };
	utf[3] = &(utf_t){0b00001111, 0b11100000, 04000,   0177777,  4    };
	utf[4] = &(utf_t){0b00000111, 0b11110000, 0200000, 04177777, 3    };
	utf[5] = &(utf_t){0};
	bytes = get_utf8_len(*chr);
	shift = utf[0]->bits_stored * (bytes - 1);
	uint32_t codep = (*chr++ & utf[bytes]->mask) << shift;
	i = 0;
	while (i < bytes)
	{
		shift -= utf[0]->bits_stored;
		codep |= ((char)*chr & utf[0]->mask) << shift;
		i++;
		chr++;
	}
	return codep;
}

int	get_displayed_symbol_len(unsigned char *num)
{
	uint32_t ucs;

	ucs = to_cp(num);
	if (ucs >= 0x1100 &&
	 (ucs <= 0x115f ||
	  ucs == 0x2329 || ucs == 0x232a ||
	  (ucs >= 0x2e80 && ucs <= 0xa4cf &&
	   ucs != 0x303f) ||
	  (ucs >= 0xac00 && ucs <= 0xd7a3) ||
	  (ucs >= 0xf900 && ucs <= 0xfaff) ||
	  (ucs >= 0xfe10 && ucs <= 0xfe19) ||
	  (ucs >= 0xfe30 && ucs <= 0xfe6f) ||
	  (ucs >= 0xff00 && ucs <= 0xff60) ||
	  (ucs >= 0xffe0 && ucs <= 0xffe6) ||
	  (ucs >= 0x20000 && ucs <= 0x2fffd) ||
	  (ucs >= 0x30000 && ucs <= 0x3fffd)))
		return (2);
	else
		return (1);
}
