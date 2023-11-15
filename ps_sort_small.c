/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:44:50 by misargsy          #+#    #+#             */
/*   Updated: 2023/10/19 07:23:14 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_insertpa(t_stacks *stacks, t_queue **head)
{
	int		depth;
	int		i;
	int		j;
	bool	rot;

	depth = stack_depth(stacks -> a);
	i = -1;
	while (++i < depth)
	{
		if (stack_get(stacks -> a, i) == stack_get(stacks -> b, 0) - 1)
		{
			j = i;
			rot = i > depth / 2;
			while (rot && i++ < depth - 1)
				ps_doop(stacks, head, &rra, "rra");
			while (!rot && i-- >= 0)
				ps_doop(stacks, head, &ra, "ra");
			ps_doop(stacks, head, &pa, "pa");
			return ;
		}
	}
	ps_doop(stacks, head, pa, "pa");
}

void	ps_three(t_stacks *stacks, t_queue **head)
{
	if ((stack_get(stacks -> a, 1) < stack_get(stacks -> a, 0))
		&& (stack_get(stacks -> a, 0) < stack_get(stacks -> a, 2)))
		ps_doop(stacks, head, &sa, "sa");
	if ((stack_get(stacks -> a, 1) < stack_get(stacks -> a, 2))
		&& (stack_get(stacks -> a, 2) < stack_get(stacks -> a, 0)))
		ps_doop(stacks, head, &rra, "rra");
	if ((stack_get(stacks -> a, 2) < stack_get(stacks -> a, 0))
		&& (stack_get(stacks -> a, 0) < stack_get(stacks -> a, 1)))
		ps_doop(stacks, head, &rra, "rra");
	if ((stack_get(stacks -> a, 2) < stack_get(stacks -> a, 1))
		&& (stack_get(stacks -> a, 1) < stack_get(stacks -> a, 0)))
	{
		ps_doop(stacks, head, &sa, "sa");
		ps_doop(stacks, head, &rra, "rra");
	}
	if ((stack_get(stacks -> a, 0) < stack_get(stacks -> a, 2))
		&& (stack_get(stacks -> a, 2) < stack_get(stacks -> a, 1)))
	{
		ps_doop(stacks, head, &sa, "sa");
		ps_doop(stacks, head, &ra, "ra");
	}
}

void	ps_four(t_stacks *stacks, t_queue **head)
{
	ps_doop(stacks, head, &pb, "pb");
	ps_three(stacks, head);
	ps_insertpa(stacks, head);
	while (stack_get(stacks -> a, 0) != 0)
		ps_doop(stacks, head, &ra, "ra");
}

void	ps_five(t_stacks *stacks, t_queue **head)
{
	ps_doop(stacks, head, &pb, "pb");
	ps_doop(stacks, head, &pb, "pb");
	ps_three(stacks, head);
	if (stack_get(stacks -> b, 0) > stack_get(stacks -> b, 1))
		ps_doop(stacks, head, &sb, "sb");
	ps_insertpa(stacks, head);
	ps_insertpa(stacks, head);
	while (stack_get(stacks -> a, 0) != 0)
		ps_doop(stacks, head, &ra, "ra");
}

void	ps_sort_small(t_stacks *stacks, t_queue **head, int depth)
{
	if (depth == 2)
		return (ps_doop(stacks, head, &sa, "sa"));
	else if (depth == 3)
		return (ps_three(stacks, head));
	else if (depth == 4)
		return (ps_four(stacks, head));
	else if (depth == 5)
		return (ps_five(stacks, head));
}
