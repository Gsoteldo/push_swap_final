/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:33:54 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/17 00:15:26 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// static void ft_leaks(void)
// {
// 	system("leaks push_swap");
// }

void	push_swap(t_stack *stacks)
{
	is_ordered(stacks->list_a);
	if (stack_size(stacks->list_a) == 1)
		free_stacks(stacks, 1, 0, 1);
	else if (stack_size(stacks->list_a) == 2)
	{
		swap_a(&stacks->list_a);
		free_stacks(stacks, 1, 0, 1);
	}
	else if (stack_size(stacks->list_a) == 3)
	{
		sort_3_numbers(&stacks->list_a);
		free_stacks(stacks, 1, 0, 1);
	}
	else if (stack_size(stacks->list_a) == 4)
		sort_4_numbers(stacks);
	//else
	//{
		push_b(&stacks->list_a, &stacks->list_b);
		push_b(&stacks->list_a, &stacks->list_b);
		cheapest(stacks);
		sort_3_numbers(&stacks->list_a);
		moves_stack_a(stacks);
	//}
}

int	main(int argc, char *argv[])
{
	t_stack	*stacks;
	//int		size;

	//atexit(ft_leaks);
	if (argv[1][0] == '\0')
		free_stacks(NULL, 0, 1, 1);
	stacks = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (checker(argc, argv, stacks) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	stacks->list_a = ft_new_a_list(argc, argv);
	stacks->list_b = NULL;
	push_swap(stacks);
	free_stacks(stacks, 1, 0, 0);
	return (0);
}
