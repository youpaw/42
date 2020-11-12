//
// Created by youpaw on 9/28/20.
//

#include "calc.h"

int		calc_get_token(t_calc *calc)
{
	static int (*handlers[N_CALC_STATES])(t_calc *) = {
			&calc_state_operator, &calc_state_number
	};

	return (handlers[calc->state](calc));
}
