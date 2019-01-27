/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:53:17 by dicanez           #+#    #+#             */
/*   Updated: 2019/01/27 06:47:16 by dicanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include <stdlib.h>
# include "ft_btree.h"

typedef struct	s_qnode
{
	t_node			*key;
	int				level;
	struct s_qnode	*next;
}				t_qnode;

typedef struct	s_queue
{
	struct s_qnode	*front;
	struct s_qnode	*rear;
}				t_queue;

void			queue_enqueue(t_queue *q, t_node *key, int level);

t_qnode			*queue_dequeue(t_queue *q);

t_qnode			*queue_create_node(t_node *key, int level);

t_queue			*queue_init(void);

#endif
