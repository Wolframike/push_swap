/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:59:13 by misargsy          #+#    #+#             */
/*   Updated: 2023/10/31 02:36:07 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_get_block(int depth)
{
	return ((int)(((float)depth / 80) * 3 + (33 / 4)));
}

static void	ps_get_thresholds(int threshold[3], int depth, int n)
{
	int	block;

	block = ps_get_block(depth);
	threshold[0] = (block * (n - 1) * 2);
	threshold[1] = (block * (n - 1) * 2) + block;
	threshold[2] = (block * (n - 1) * 2) + (block * 2);
}

static void	ps_init_partition_helper(
		int thresholds[3], t_stacks *stacks, t_queue **head, int *count)
{
	int	depth;

	depth = stack_depth(stacks -> a);
	if ((thresholds[0] <= stack_get(stacks -> a, 0))
		&& (stack_get(stacks -> a, 0) < thresholds[1]))
	{
		ps_fetchpb(stacks, head, stack_get(stacks -> a, 0));
		(*count)++;
	}
	else if ((thresholds[1] <= stack_get(stacks -> a, 0))
		&& (stack_get(stacks -> a, 0) < thresholds[2]))
	{
		ps_fetchpb(stacks, head, stack_get(stacks -> a, 0));
		ps_doop(stacks, head, &rb, "rb");
		(*count)++;
	}
	else
		ps_doop(stacks, head, &ra, "ra");
}

static void	ps_init_partition(t_stacks *stacks, t_queue **head)
{
	int	depth;
	int	i;
	int	count;
	int	thresholds[3];

	depth = stack_depth(stacks -> a);
	i = 1;
	while (true)
	{
		count = 0;
		ps_get_thresholds(thresholds, depth, i);
		if (thresholds[2] > depth)
			thresholds[2] = depth;
		while (count != (thresholds[2] - thresholds[0]))
			ps_init_partition_helper(thresholds, stacks, head, &count);
		if (thresholds[2] == depth)
			break ;
		i++;
	}
}

void	ps_sort(t_stacks *stacks, t_queue **head)
{
	int	depth;
	int	n;

	depth = stack_depth(stacks -> a);
	if (ps_issorted(stacks -> a))
		return ;
	if (depth <= 5)
		ps_sort_small(stacks, head, depth);
	else
	{
		ps_init_partition(stacks, head);
		n = depth - 1;
		while (stack_depth(stacks -> b) != 0)
		{
			if ((stack_depth(stacks -> a) > 0)
				&& (stack_get(stacks -> a, 0) == n))
			{
				ps_fetchpa(stacks, head, n-- + 1);
				ps_doop(stacks, head, &sa, "sa");
			}
			else
				ps_fetchpa(stacks, head, n--);
		}
	}
}
