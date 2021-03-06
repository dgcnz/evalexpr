/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:23:28 by dicanez           #+#    #+#             */
/*   Updated: 2019/01/27 14:59:21 by dicanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_eval.h"

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			ft_putnbr(eval_expr(av[i]));
			ft_putchar('\n');
			++i;
		}
	}
	return (0);
}
