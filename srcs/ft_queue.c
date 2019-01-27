/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:51:57 by dicanez           #+#    #+#             */
/*   Updated: 2019/01/27 06:47:16 by dicanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

t_qnode	*queue_create_node(t_node *key, int level)
{
	t_qnode *qnode;

	qnode = malloc(sizeof(t_qnode));
	qnode->key = key;
	qnode->level = level;
	qnode->next = 0;
	return (qnode);
}

void	queue_enqueue(t_queue *q, t_node *key, int level)
{
	t_qnode *qnode;

	qnode = queue_create_node(key, level);
	if (q->rear == 0)
	{
		q->front = qnode;
		q->rear = qnode;
		return ;
	}
	q->rear->next = qnode;
	q->rear = qnode;
}

t_qnode	*queue_dequeue(t_queue *q)
{
	t_qnode *qnode;

	if (q->front == 0)
		return (0);
	qnode = q->front;
	q->front = q->front->next;
	if (q->front == 0)
		q->rear = 0;
	return (qnode);
}

t_queue	*queue_init(void)
{
	t_queue		*q;

	q = malloc(sizeof(t_queue));
	q->front = 0;
	q->rear = 0;
	return (q);
}
