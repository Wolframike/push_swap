/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stackops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:31:24 by misargsy          #+#    #+#             */
/*   Updated: 2023/10/18 02:48:30 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*stacks_init(void)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
		return (ps_exit(NULL, false));
	stacks -> a = NULL;
	stacks -> b = NULL;
	return (stacks);
}

bool	stack_push(t_node **stack, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (false);
	new -> value = value;
	new -> up = NULL;
	if ((*stack) == NULL)
		new -> down = NULL;
	else
	{
		new -> down = (*stack);
		(*stack)-> up = new;
	}
	(*stack) = new;
	return (true);
}

int	stack_get(t_node *stack, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		stack = stack -> down;
		i++;
	}
	return (stack -> value);
}

size_t	stack_depth(t_node *stack)
{
	size_t	depth;

	depth = 0;
	while (stack != NULL)
	{
		depth++;
		stack = stack -> down;
	}
	return (depth);
}

void	stack_clear(t_node *stack)
{
	t_node	*tmp;

	while (stack != NULL)
	{
		tmp = stack -> down;
		free(stack);
		stack = tmp;
	}
}
