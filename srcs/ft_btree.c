/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:35:41 by dicanez           #+#    #+#             */
/*   Updated: 2019/01/27 13:19:46 by dicanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "ft_queue.h"
#include "ft.h"

void	btree_apply_by_level(t_node *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_queue		*q;
	t_qnode		*current;
	int			level;
	int			flag;

	q = queue_init();
	queue_enqueue(q, root, (level = 0));
	queue_enqueue(q, 0, 0);
	flag = 1;
	while (!(q->front->key == 0 && q->front->key == q->rear->key))
	{
		current = queue_dequeue(q);
		if (current->key == 0)
			queue_enqueue(q, 0, (flag = 1) && level++);
		else
		{
			applyf(current->key->data, level, flag);
			if ((flag = 0) || current->key->left)
				queue_enqueue(q, current->key->left, level);
			if ((flag = 0) || current->key->right)
				queue_enqueue(q, current->key->right, level);
		}
	}
}

t_node	*ft_create_node(t_node *left, t_node *right, t_string data)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	node->data = data;
	node->left = left;
	node->right = right;
	return (node);
}

int		ft_btree_traverse(t_node *root, t_funptr (*ft_getfx)(t_string))
{
	int			res_left;
	int			res_right;
	t_funptr	f;

	if (!(root->left) && !(root->right))
	{
		return (ft_atoi(root->data));
	}
	else
	{
		f = ft_getfx(root->data);
		res_left = ft_btree_traverse(root->left, ft_getfx);
		res_right = ft_btree_traverse(root->right, ft_getfx);
		return (f(res_left, res_right));
	}
}
