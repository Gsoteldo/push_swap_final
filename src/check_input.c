/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:54:30 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/13 19:42:53 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	is_max_int(char *str)
{
	if (ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
		free_stacks(NULL, 0, 1, 1);
}

int	is_repeated(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	comprobation(int argc, char **argv, t_stack *stacks)
{
	int		i;
	size_t	j;

	j = 0;
	i = 1;
	if (argv[i][0] == '\0')
		free_stacks(stacks, 1, 0, 1);
	while (i < argc)
	{
		while (j < ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (j == 0 && ft_strlen(argv[i]) != 1 && (argv[i][j] == '-' || argv[i][j] == '+'))
				{
					j++;
					continue;
				}
				free_stacks(stacks, 1, 1, 1);
			}
			j++;
		}
		i++;
	}
}

int	checker(int argc, char **argv, t_stack *stacks)
{
	int	i;
	int	num;

	i = 1;
	num = 1;
	if (argc < 2)
		free_stacks(stacks, 1, 1, 1);
	while (i < argc)
	{
		is_max_int(argv[i]);
		comprobation(argc, argv, stacks);
		if (is_repeated(argc, argv) == 1)
		{
			num = 0;
			free_stacks(stacks, 0, 1, 1);
			break ;
		}
		i++;
	}
	return (num);
}
