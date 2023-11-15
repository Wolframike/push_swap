/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_queueops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 02:31:59 by misargsy          #+#    #+#             */
/*   Updated: 2023/10/18 03:26:17 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	queue_enqueue(t_queue **head, char *op)
{
	t_queue	*new;
	t_queue	*cur;

	new = (t_queue *)malloc(sizeof(t_queue));
	if (new == NULL)
		return (false);
	new -> op = op;
	new -> next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (true);
	}
	cur = *head;
	while (cur -> next != NULL)
		cur = cur -> next;
	cur -> next = new;
	return (true);
}

void	queue_clear(t_queue *head)
{
	t_queue	*tmp;

	while (head != NULL)
	{
		tmp = head -> next;
		free(head);
		head = tmp;
	}
}
