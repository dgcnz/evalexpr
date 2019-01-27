/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:06:38 by dicanez           #+#    #+#             */
/*   Updated: 2019/01/26 20:03:29 by dicanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVAL_H
# define FT_EVAL_H

# include "ft_types.h"
# include "ft_parser.h"
# include "ft_math.h"

int			eval_expr(t_string expression);

t_funptr	ft_getfx(t_string op);

void		test_tokenizer(t_string expression);

void		test_parser(t_string expression);

#endif
