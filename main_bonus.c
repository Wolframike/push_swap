/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:50:11 by misargsy          #+#    #+#             */
/*   Updated: 2023/11/11 15:55:49 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_checker_exit(t_stacks *stacks, bool valid)
{
	stack_clear(stacks -> a);
	stack_clear(stacks -> b);
	free(stacks);
	if (!valid)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

static void	ps_doop_checker(t_stacks *stacks, char *op, bool *valid)
{
	if (ft_strncmp(op, "pa\n", 3) == 0)
		pa(stacks);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		pb(stacks);
	else if (ft_strncmp(op, "sa\n", 3) == 0)
		sa(stacks);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(stacks);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(stacks);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ra(stacks);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rb(stacks);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rr(stacks);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rra(stacks);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb(stacks);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(stacks);
	else
		*valid = false;
}

static void	ps_doop_loop(t_stacks *stacks)
{
	char	*op;
	bool	valid;

	valid = true;
	while (valid)
	{
		op = get_next_line(STDIN_FILENO);
		if (op == NULL)
			break ;
		ps_doop_checker(stacks, op, &valid);
		free(op);
		if (!valid)
			ps_checker_exit(stacks, valid);
	}
}

static void	ps_checker_terminator(bool sorted)
{
	if (sorted)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			*input;
	size_t		size;
	bool		sorted;

	input = ps_parse(argc, argv, &size);
	stacks = stacks_init();
	while (size--)
	{
		if (!stack_push(&stacks -> a, input[size]))
		{
			free(input);
			stack_clear(stacks -> a);
			free(stacks);
			ps_checker_exit(NULL, false);
		}
	}
	free(input);
	ps_doop_loop(stacks);
	sorted = (ps_issorted(stacks -> a) && (stacks -> b == NULL));
	stack_clear(stacks -> a);
	stack_clear(stacks -> b);
	free(stacks);
	ps_checker_terminator(sorted);
}
