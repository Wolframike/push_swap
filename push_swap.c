/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:00:49 by misargsy          #+#    #+#             */
/*   Updated: 2023/10/31 00:56:49 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ps_exit(char **arr, bool f)
{
	if (f)
		ps_free2darr(arr);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
	return (NULL);
}

int	*ps_parse(int argc, char **argv, size_t *size)
{
	char		**sinput;
	int			*input;
	size_t		len;
	size_t		i;

	if (argc <= 1)
		exit(EXIT_SUCCESS);
	sinput = ps_parse_split(argc, argv);
	len = 0;
	while (sinput[len] != NULL && len != INT_MAX)
		len++;
	if (sinput[len] != NULL && len == INT_MAX)
		return (ps_exit(sinput, argc == 2));
	input = (int *)malloc(sizeof(int) * len);
	if (input == NULL)
		return (ps_exit(sinput, argc == 2));
	i = 0;
	while (i++ < len)
		input[i - 1] = ft_atoi(sinput[i - 1]);
	if (ps_isduplicate(input, len) || !ps_coco(input, len))
		return (ps_exit(sinput, argc == 2));
	if (argc == 2)
		ps_free2darr(sinput);
	*size = len;
	return (input);
}
