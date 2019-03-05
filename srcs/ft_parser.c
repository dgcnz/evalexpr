/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:28:44 by dicanez           #+#    #+#             */
/*   Updated: 2019/01/27 14:43:14 by dicanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void		ft_eat_tkn(t_type type, t_string expression, int *pos,
						t_token **current_tkn)
{
	if (type == (*current_tkn)->type)
		*current_tkn = ft_get_next_token(expression, pos);
}

t_node		*ft_factor(t_string expression, int *pos, t_token **current_tkn)
{
	t_node		*node;
	t_string	value;

	if ((*current_tkn)->type == INTEGER)
	{
		value = (*current_tkn)->value;
		ft_eat_tkn(INTEGER, expression, pos, current_tkn);
		return (ft_create_node(NULL, NULL, value));
	}
	else if ((*current_tkn)->type == LPAR)
	{
		ft_eat_tkn(LPAR, expression, pos, current_tkn);
		node = ft_expr(expression, pos, current_tkn);
		ft_eat_tkn(RPAR, expression, pos, current_tkn);
		return (node);
	}
	else if ((*current_tkn)->type == OP_P2)
	{
		value = (*current_tkn)->value;
		ft_eat_tkn(OP_P2, expression, pos, current_tkn);
		node = ft_factor(expression, pos, current_tkn);
		return (ft_create_node(NULL, node, value));
	}
	else
		return (NULL);
}

t_node		*ft_term(t_string expression, int *pos, t_token **current_tkn)
{
	t_node		*node;
	t_string	value;

	node = ft_factor(expression, pos, current_tkn);
	while (*current_tkn && ((*current_tkn)->type == OP_P1))
	{
		value = (*current_tkn)->value;
		ft_eat_tkn(OP_P1, expression, pos, current_tkn);
		node = ft_create_node(node,
				ft_factor(expression, pos, current_tkn), value);
	}
	return (node);
}

t_node		*ft_expr(t_string expression, int *pos, t_token **current_tkn)
{
	t_node		*node;
	t_string	value;

	node = ft_term(expression, pos, current_tkn);
	while (*current_tkn && ((*current_tkn)->type == OP_P2))
	{
		value = (*current_tkn)->value;
		ft_eat_tkn(OP_P2, expression, pos, current_tkn);
		node = ft_create_node(node,
				ft_term(expression, pos, current_tkn), value);
	}
	return (node);
}

t_node		*ft_parse(t_string expression)
{
	t_token		*current_tkn;
	int			pos;

	pos = 0;
	current_tkn = ft_get_next_token(expression, &pos);
	return (ft_expr(expression, &pos, &current_tkn));
}
