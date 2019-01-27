/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:28:39 by dicanez           #+#    #+#             */
/*   Updated: 2019/01/27 11:38:06 by dicanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tokenizer.h"
#include <stdlib.h>

t_string	ft_get_num(t_string expr, int *pos)
{
	int			i;
	int			temp_pos;
	t_string	num;

	i = *pos;
	while (ft_is_num(expr[i]))
		++i;
	num = malloc(sizeof(char) * (i - *pos + 1));
	num[i] = '\0';
	temp_pos = *pos;
	while (*pos < i)
	{
		num[(*pos) - temp_pos] = expr[*pos];
		*pos += 1;
	}
	return (num);
}

t_string	ft_get_tkn(t_string expr, int *pos)
{
	t_string num;

	num = malloc(sizeof(char) * 2);
	num[0] = expr[*pos];
	num[1] = '\0';
	*pos += 1;
	return (num);
}

t_token		*ft_create_token(t_type type, t_string value)
{
	t_token *token;

	token = malloc(sizeof(t_token));
	token->type = type;
	token->value = value;
	return (token);
}

t_token		*ft_get_next_token(t_string expr, int *pos)
{
	t_token *token;

	if (expr[*pos])
	{
		if (ft_is_num(expr[*pos]))
			token = ft_create_token(INTEGER, ft_get_num(expr, pos));
		else if (expr[*pos] == '*' || expr[*pos] == '/'
				|| expr[*pos] == '%')
			token = ft_create_token(OP_P1, ft_get_tkn(expr, pos));
		else if (expr[*pos] == '+' || expr[*pos] == '-')
			token = ft_create_token(OP_P2, ft_get_tkn(expr, pos));
		else if (expr[*pos] == '(' || expr[*pos] == ')')
			token = ft_create_token((int)expr[*pos], ft_get_tkn(expr, pos));
		else
		{
			*pos += 1;
			return (ft_get_next_token(expr, pos));
		}
		return (token);
	}
	return (NULL);
}
