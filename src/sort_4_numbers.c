/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:43:34 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/12 19:35:07 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_4_numbers(t_stack *stacks)
{
	stacks->moves = (t_moves *)malloc(sizeof(t_moves));
	stacks->cheapest = (t_moves *)malloc(sizeof(t_moves));
	stacks->value = (t_value *)malloc(sizeof(t_value));
	push_b(&stacks->list_a, &stacks->list_b);
	sort_3_numbers(&stacks->list_a);
	moves_stack_a(stacks);
	free_stacks(stacks, 1, 0, 1);
}
