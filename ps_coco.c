/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_coco.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:48:13 by misargsy          #+#    #+#             */
/*   Updated: 2023/10/31 00:46:24 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_bubblesort(int *arr, size_t size)
{
	size_t	i;
	size_t	j;
	int		temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

bool	ps_coco(int *arr, size_t size)
{
	int		*sorted;
	size_t	i;
	size_t	j;

	sorted = (int *)malloc(sizeof(int) * size);
	if (sorted == NULL)
		return (false);
	ft_memcpy(sorted, arr, sizeof(int) * size);
	ps_bubblesort(sorted, size);
	i = 0;
	while (i++ < size)
	{
		j = 0;
		while (j++ < size)
		{
			if (arr[i - 1] == sorted[j - 1])
			{
				arr[i - 1] = j - 1;
				break ;
			}
		}
	}
	free(sorted);
	return (true);
}
