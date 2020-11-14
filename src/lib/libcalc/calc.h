/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:03:22 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:03:28 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H
# define CALC_H

# include <stddef.h>
# include "cc_vec.h"

# define N_OPERATORS 15
# define N_BINARY_OPERATORS 13
# define N_UNARY_OPERATORS 2
# define N_CALC_STATES 2
# define CALC_VEC_CAPACITY 15

enum						e_calc_type
{
	c_negative,
	c_positive,
	c_multiplication,
	c_division,
	c_modulo,
	c_subtraction,
	c_addition,
	c_greater,
	c_lower,
	c_greater_or_equal,
	c_lower_or_equal,
	c_equal,
	c_not_equal,
	c_and,
	c_or,
	c_none,
	c_parenthesis,
	c_number
};

enum						e_calc_state
{
	c_st_operator,
	c_st_number
};

struct						s_calc_token
{
	char				*raw;
	enum e_calc_type	type;
	int					priority;
};

struct						s_calc_eval
{
	int					val;
	enum e_calc_type	type;
};

struct						s_calc
{
	char				*raw;
	size_t				index;
	size_t				size;
	enum e_calc_state	state;
	t_vec				*tokens;
};

typedef enum e_calc_type	t_calc_type;
typedef enum e_calc_state	t_calc_state;
typedef struct s_calc_token	t_calc_token;
typedef struct s_calc_eval	t_calc_eval;
typedef struct s_calc		t_calc;

int							calc_get_priority(t_calc_type type);

int							calc_get_operator(t_calc *calc);
int							calc_get_number(t_calc *calc);

int							calc_state_operator(t_calc *calc);
int							calc_state_number(t_calc *calc);
int							calc_get_token(t_calc *calc);

int							calc_is_unary(t_calc_type type);
int							calc_is_binary(t_calc_type type);
int							calc_is_operator(t_calc_type type);
int							calc_is_forbidden(char c);

int							calc_operate_mlt(t_calc_eval *a, t_calc_eval *b);
int							calc_operate_div(t_calc_eval *a, t_calc_eval *b);
int							calc_operate_mod(t_calc_eval *a, t_calc_eval *b);
int							calc_operate_sub(t_calc_eval *a, t_calc_eval *b);
int							calc_operate_add(t_calc_eval *a, t_calc_eval *b);
int							calc_operate_grt(t_calc_eval *a, t_calc_eval *b);
int							calc_operate_les(t_calc_eval *a, t_calc_eval *b);
int							calc_operate_goe(t_calc_eval *a, t_calc_eval *b);
int							calc_operate_loe(t_calc_eval *a, t_calc_eval *b);
int							calc_operate_eql(t_calc_eval *a, t_calc_eval *b);
int							calc_operate_neq(t_calc_eval *a, t_calc_eval *b);
int							calc_operate_and(t_calc_eval *a, t_calc_eval *b);
int							calc_operate_or(t_calc_eval *a, t_calc_eval *b);

int							calc_operate(t_vec *stack, t_calc_token *token);
int							calc_evaluate(char **raw, t_vec *postfix);
t_vec						*calc_convert_to_postfix(t_vec *tokens);
int							calc_tokenize(t_calc *calc);
int							sh_calc(char **raw);

#endif
