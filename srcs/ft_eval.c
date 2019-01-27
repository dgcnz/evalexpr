/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:06:54 by dicanez           #+#    #+#             */
/*   Updated: 2019/01/27 13:23:22 by dicanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eval.h"

t_funptr	ft_getfx(t_string op)
{
	if (op[0] == '+')
		return (&ft_add);
	else if (op[0] == '-')
		return (&ft_sub);
	else if (op[0] == '*')
		return (&ft_mul);
	else if (op[0] == '/')
		return (&ft_div);
	else
		return (&ft_mod);
}

int			eval_expr(t_string expression)
{
	t_node	*ast_root;
	int		res;

	ast_root = ft_parse(expression);
	res = ft_btree_traverse(ast_root, &ft_getfx);
	return (res);
}

void		test_tokenizer(t_string expression)
{
	int		i;
	t_token	*tkn;

	i = 0;
	while ((tkn = ft_get_next_token(expression, &i)))
	{
		ft_putstr("TOKEN : {type: ");
		ft_putnbr(tkn->type);
		ft_putstr(", value: ");
		ft_putstr(tkn->value);
		ft_putstr("}\n");
	}
}

void		ft_print(void *item, int current_level, int is_first_elem)
{
	if (is_first_elem)
	{
		ft_putstr("\nlevel ");
		ft_putnbr(current_level);
		ft_putstr(" | ");
	}
	ft_putstr((char *)item);
	ft_putstr("  ");
}

void		test_parser(t_string expression)
{
	t_node *ast_root;

	ft_putstr("Creating ast_root...\n");
	ast_root = ft_parse(expression);
	ft_putstr("Done.\n");
	ft_putstr("Applying traversal...\n");
	btree_apply_by_level(ast_root, &ft_print);
	ft_putstr("Done.\n");
}
