/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:29:07 by misargsy          #+#    #+#             */
/*   Updated: 2023/10/21 03:53:23 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ps_free2darr(char **arr)
{
	size_t	i;

	if (arr == NULL)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

bool	ps_isnumber(char **split)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (split[i] != NULL)
	{
		if (split[i][0] == '\0')
			return (false);
		j = 0;
		if (split[i][j] == '-' || split[i][j] == '+')
			j++;
		while (split[i][j] != '\0')
		{
			if (!ft_isdigit(split[i][j]))
				return (false);
			j++;
		}
		if (j == 1 && (split[i][0] == '-' || split[i][0] == '+'))
			return (false);
		i++;
	}
	if (i == 0)
		return (false);
	return (true);
}

bool	ps_isoverflow(char **split, char *max, char *min)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	while (split[i] != NULL)
	{
		j = 0;
		if (split[i][j] == '-' || split[i][j] == '+')
			j++;
		while (split[i][j] != '\0')
		{
			if (!ft_isdigit(split[i][j]))
				return (false);
			j++;
		}
		len = ft_strlen(split[i]);
		if ((len > 11)
			|| (len == 10 && ft_strncmp(split[i], max, ft_strlen(max)) > 0)
			|| (len == 11 && ft_strncmp(split[i], min, ft_strlen(min)) > 0))
			return (true);
		i++;
	}
	return (false);
}

bool	ps_isduplicate(int *input, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (input[i] == input[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

char	**ps_parse_split(int argc, char **argv)
{
	char	**input;
	char	*max;
	char	*min;

	max = ft_itoa(INT_MAX);
	min = ft_itoa(INT_MIN);
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		if (input == NULL)
			ps_exit(NULL, false);
	}
	else
		input = argv + 1;
	if (!ps_isnumber(input) || ps_isoverflow(input, max, min))
	{
		free(max);
		free(min);
		return (ps_exit(input, argc == 2));
	}
	free(max);
	free(min);
	return (input);
}
