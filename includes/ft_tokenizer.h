/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:56:44 by dicanez           #+#    #+#             */
/*   Updated: 2019/01/27 11:19:26 by dicanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKENIZER_H
# define FT_TOKENIZER_H

# include "ft_types.h"
# include "ft.h"

typedef enum	e_type
{
	INTEGER = 0,
	OP_P1 = 1,
	OP_P2 = 2,
	LPAR = 40,
	RPAR = 41
}				t_type;

typedef struct	s_token
{
	t_type		type;
	t_string	value;

}				t_token;

t_string		ft_get_num(t_string expr, int *pos);

t_string		ft_get_tkn(t_string expr, int *pos);

t_token			*ft_create_token(t_type type, t_string value);

t_token			*ft_get_next_token(t_string expression, int *pos);

#endif
