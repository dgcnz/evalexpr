/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:04:20 by dicanez           #+#    #+#             */
/*   Updated: 2019/01/27 06:48:49 by dicanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_eval.h"

int main (int ac, char **av)
{
	if (ac > 1)
	{
		test_parser(av[1]);
		ft_putchar('\n');
	}
	return (0);
}