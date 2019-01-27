/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 09:52:38 by dicanez           #+#    #+#             */
/*   Updated: 2019/01/27 08:16:16 by dicanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h>
# include "ft_types.h"

typedef struct	s_node
{
	struct s_node	*left;
	struct s_node	*right;
	t_string		data;
}				t_node;

t_node			*ft_create_node(t_node *left, t_node *right, t_string data);

int				ft_btree_traverse(t_node *root, t_funptr (*ft_getfx)(t_string));

void			btree_apply_by_level(t_node *root, void (*applyf)(void *item,
				int current_level, int is_first_elem));

#endif
