/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:50:00 by misargsy          #+#    #+#             */
/*   Updated: 2023/11/11 15:55:46 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_queue		*head;
	int			*input;
	size_t		size;

	input = ps_parse(argc, argv, &size);
	stacks = stacks_init();
	head = NULL;
	while (size--)
	{
		if (!stack_push(&stacks -> a, input[size]))
		{
			free(input);
			stack_clear(stacks -> a);
			free(stacks);
			ps_exit(NULL, false);
		}
	}
	free(input);
	if (!ps_issorted(stacks -> a))
		ps_sort(stacks, &head);
	stack_clear(stacks -> a);
	free(stacks);
	ps_printqueue(head);
	return (queue_clear(head), 0);
}
