/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_optimization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 02:51:27 by misargsy          #+#    #+#             */
/*   Updated: 2023/10/31 00:46:37 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_doop(t_stacks *stacks, t_queue **head,
				void (*op)(t_stacks*), char *str)
{
	if (!queue_enqueue(head, str))
	{
		stack_clear(stacks -> a);
		stack_clear(stacks -> b);
		queue_clear(*head);
		free(stacks);
		ps_exit(NULL, false);
	}
	if (stacks != NULL)
		(*op)(stacks);
}

static void	ps_count_rot(t_queue **head, int *a, int *b)
{
	*a = 0;
	*b = 0;
	while (*head != NULL)
	{
		if (ft_strncmp((*head)-> op, "ra", 2) == 0)
			(*a)++;
		else if (ft_strncmp((*head)-> op, "rb", 2) == 0)
			(*b)++;
		else if (ft_strncmp((*head)-> op, "rra", 3) == 0)
			(*a)--;
		else if (ft_strncmp((*head)-> op, "rrb", 3) == 0)
			(*b)--;
		else
			break ;
		*head = (*head)-> next;
	}
}

static void	ps_reduce(int *a, int *b)
{
	bool	rot;
	int		dir;

	if ((*a > 0) != (*b > 0))
		return ;
	rot = (*a > 0);
	if (rot)
		dir = -1;
	else
		dir = 1;
	while ((*a != 0) && (*b != 0))
	{
		if (rot)
			ft_printf("rr\n");
		else
			ft_printf("rrr\n");
		(*a) += dir;
		(*b) += dir;
	}
}

static void	ps_skip_rot(t_queue **head)
{
	int	a;
	int	b;

	ps_count_rot(head, &a, &b);
	ps_reduce(&a, &b);
	while (a < 0)
	{
		ft_printf("rra\n");
		a++;
	}
	while (a > 0)
	{
		ft_printf("ra\n");
		a--;
	}
	while (b < 0)
	{
		ft_printf("rrb\n");
		b++;
	}
	while (b > 0)
	{
		ft_printf("rb\n");
		b--;
	}
}

void	ps_printqueue(t_queue *head)
{
	char	*op;

	while (head != NULL)
	{
		op = head -> op;
		if (op[0] == 'r')
			ps_skip_rot(&head);
		else
		{
			ft_printf("%s\n", op);
			head = head -> next;
		}
	}
}
