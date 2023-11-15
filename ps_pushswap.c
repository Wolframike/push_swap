/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 23:16:37 by misargsy          #+#    #+#             */
/*   Updated: 2023/10/12 02:53:02 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	if (stacks -> a == NULL || stacks -> a -> down == NULL)
		return ;
	if (stacks -> a -> down -> down == NULL)
	{
		stacks -> a -> up = stacks -> a -> down;
		stacks -> a -> down = NULL;
		stacks -> a -> up -> up = NULL;
		stacks -> a -> up -> down = stacks -> a;
	}
	else
	{
		stacks -> a -> up = stacks -> a -> down;
		stacks -> a -> down = stacks -> a -> down -> down;
		stacks -> a -> up -> up = NULL;
		stacks -> a -> up -> down = stacks -> a;
		stacks -> a -> down -> up = stacks -> a;
	}
	stacks -> a = stacks -> a -> up;
}

void	sb(t_stacks *stacks)
{
	if (stacks -> b == NULL || stacks -> b -> down == NULL)
		return ;
	if (stacks -> b -> down -> down == NULL)
	{
		stacks -> b -> up = stacks -> b -> down;
		stacks -> b -> down = NULL;
		stacks -> b -> up -> up = NULL;
		stacks -> b -> up -> down = stacks -> b;
	}
	else
	{
		stacks -> b -> up = stacks -> b -> down;
		stacks -> b -> down = stacks -> b -> down -> down;
		stacks -> b -> up -> up = NULL;
		stacks -> b -> up -> down = stacks -> b;
		stacks -> b -> down -> up = stacks -> b;
	}
	stacks -> b = stacks -> b -> up;
}

void	pa(t_stacks *stacks)
{
	t_node	*tmp;

	if (stacks -> b == NULL)
		return ;
	tmp = stacks -> b;
	stacks -> b = stacks -> b -> down;
	if (stacks -> b != NULL)
		stacks -> b -> up = NULL;
	if (stacks -> a == NULL)
	{
		stacks -> a = tmp;
		stacks -> a -> up = NULL;
		stacks -> a -> down = NULL;
	}
	else
	{
		stacks -> a -> up = tmp;
		tmp -> down = stacks -> a;
		tmp -> up = NULL;
		stacks -> a = tmp;
	}
}

void	pb(t_stacks *stacks)
{
	t_node	*tmp;

	if (stacks -> a == NULL)
		return ;
	tmp = stacks -> a;
	stacks -> a = stacks -> a -> down;
	if (stacks -> a != NULL)
		stacks -> a -> up = NULL;
	if (stacks -> b == NULL)
	{
		stacks -> b = tmp;
		stacks -> b -> up = NULL;
		stacks -> b -> down = NULL;
	}
	else
	{
		stacks -> b -> up = tmp;
		tmp -> down = stacks -> b;
		tmp -> up = NULL;
		stacks -> b = tmp;
	}
}
