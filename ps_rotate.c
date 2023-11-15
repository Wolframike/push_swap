/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:28:48 by misargsy          #+#    #+#             */
/*   Updated: 2023/10/12 02:53:37 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	t_node	*tmp;

	if (stacks -> a == NULL || stacks -> a -> down == NULL)
		return ;
	tmp = stacks -> a;
	while (tmp -> down != NULL)
		tmp = tmp -> down;
	tmp -> down = stacks -> a;
	stacks -> a -> up = tmp;
	stacks -> a = stacks -> a -> down;
	stacks -> a -> up -> down = NULL;
	stacks -> a -> up = NULL;
}

void	rb(t_stacks *stacks)
{
	t_node	*tmp;

	if (stacks -> b == NULL || stacks -> b -> down == NULL)
		return ;
	tmp = stacks -> b;
	while (tmp -> down != NULL)
		tmp = tmp -> down;
	tmp -> down = stacks -> b;
	stacks -> b -> up = tmp;
	stacks -> b = stacks -> b -> down;
	stacks -> b -> up -> down = NULL;
	stacks -> b -> up = NULL;
}

void	rra(t_stacks *stacks)
{
	t_node	*tmp;

	if (stacks -> a == NULL || stacks -> a -> down == NULL)
		return ;
	tmp = stacks -> a;
	while (tmp -> down != NULL)
		tmp = tmp -> down;
	tmp -> down = stacks -> a;
	stacks -> a -> up = tmp;
	stacks -> a = tmp;
	stacks -> a -> up -> down = NULL;
	stacks -> a -> up = NULL;
}

void	rrb(t_stacks *stacks)
{
	t_node	*tmp;

	if (stacks -> b == NULL || stacks -> b -> down == NULL)
		return ;
	tmp = stacks -> b;
	while (tmp -> down != NULL)
		tmp = tmp -> down;
	tmp -> down = stacks -> b;
	stacks -> b -> up = tmp;
	stacks -> b = tmp;
	stacks -> b -> up -> down = NULL;
	stacks -> b -> up = NULL;
}
