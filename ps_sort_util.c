/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:36:11 by misargsy          #+#    #+#             */
/*   Updated: 2023/11/11 15:52:12 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ps_issorted(t_node *head)
{
	t_node	*node;

	if (head == NULL)
		return (false);
	node = head;
	while (node -> down != NULL)
	{
		if (node -> value > node -> down -> value)
			return (false);
		node = node -> down;
	}
	return (true);
}

void	ps_fetchpa(t_stacks *stacks, t_queue **head, int n)
{
	int	depth;
	int	d;
	int	h;

	depth = stack_depth(stacks -> b);
	d = 0;
	h = 0;
	while ((stack_get(stacks -> b, d) != n)
		&& (stack_get(stacks -> b, d) != n - 1))
		d++;
	while ((stack_get(stacks -> b, depth - h - 1) != n)
		&& (stack_get(stacks -> b, depth - h - 1) != n - 1))
		h++;
	if (h < d)
		d = depth - h - 1;
	if (d < depth / 2)
		while (d-- > 0)
			ps_doop(stacks, head, &rb, "rb");
	else
		while (d++ < depth)
			ps_doop(stacks, head, &rrb, "rrb");
	ps_doop(stacks, head, &pa, "pa");
}

void	ps_fetchpb(t_stacks *stacks, t_queue **head, int n)
{
	int	depth;
	int	d;
	int	h;

	depth = stack_depth(stacks -> a);
	d = 0;
	h = 0;
	while ((stack_get(stacks -> a, d) != n))
		d++;
	while ((stack_get(stacks -> a, depth - h - 1) != n))
		h++;
	if (h < d)
		d = depth - h - 1;
	if (d < depth / 2)
		while (d-- > 0)
			ps_doop(stacks, head, &ra, "ra");
	else
		while (d++ < depth)
			ps_doop(stacks, head, &rra, "rra");
	ps_doop(stacks, head, &pb, "pb");
}
