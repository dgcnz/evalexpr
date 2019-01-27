/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:19:56 by dicanez           #+#    #+#             */
/*   Updated: 2019/01/27 13:24:44 by dicanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "ft_btree.h"
# include "ft_tokenizer.h"
# include "ft_types.h"

void	ft_eat_tkn(t_type type, t_string expression, int *pos,
		t_token **current_tkn);

t_node	*ft_expr(t_string expression, int *pos, t_token **current_tkn);

t_node	*ft_term(t_string expression, int *pos, t_token **current_tkn);

t_node	*ft_factor(t_string expression, int *pos, t_token **current_tkn);

t_node	*ft_parse(t_string expression);

#endif
