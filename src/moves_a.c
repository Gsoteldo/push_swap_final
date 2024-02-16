/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:02:30 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/17 00:06:27 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	moves(t_stack *stacks, int push_flag)
{
	while (stacks->moves->ra-- != 0)
		rotate_a(&stacks->list_a);
	while (stacks->moves->rra-- != 0)
		r_rotate_a(&stacks->list_a);
	if (push_flag == 1)
		push_a(&stacks->list_a, &stacks->list_b);
	
}

void	new_order_min_stack(t_stack *stacks, char flag)
{
	int	index;
	int size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	index = find_index(stacks->list_a, stacks->value->min_a);
	size = stack_size(stacks->list_a);
	if (stacks->list_a->content != stacks->value->min_a)
	{
		if (size % 2 == 0)
		{
			if (index + 1 > size / 2)
				stacks->moves->rra = size - index;
			else
				stacks->moves->ra = index;
		}
		else
		{
			if (index > size / 2)
				stacks->moves->rra = size - index;
			else
				stacks->moves->ra = index;
		}
	}
	moves(stacks, flag);
}

void	new_order_max_stack(t_stack *stacks, int flag)
{
	int	index;
	int size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (ft_last(stacks->list_a)->content != stacks->value->max_a)
	{
		index = find_index(stacks->list_a, stacks->value->max_a);
		size = stack_size(stacks->list_a);
		if (size % 2 == 0)
		{
			if (index + 1 > size / 2)
				stacks->moves->rra = (size - index) - 1;
			else
				stacks->moves->ra = index + 1;
		}
		else
		{
			if (index > size / 2)
				stacks->moves->rra = (size - index) - 1;
			else
				stacks->moves->ra = index + 1;
		}
	}
	moves(stacks, flag);
}

void	new_elem_in_a(t_stack *stacks, t_linked_list *stack_b)
{
	int	index;
	int size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->list_a->content != search_number_stack_a(stacks->list_a, stack_b->content))
	{
		size = stack_size(stacks->list_a);
		index = find_index(stacks->list_a, search_number_stack_a(stacks->list_a, stack_b->content));
		if (size % 2 == 0)
		{
			if (index + 1 > size / 2)
				stacks->moves->rra = (size - index);
			else
				stacks->moves->ra = index;
		}
		else
		{
			if (index > size / 2)
				stacks->moves->rra = size - index;
			else
				stacks->moves->ra = index;
		}
	}
	moves(stacks, 1);
}

void	moves_stack_a(t_stack *stacks)
{
	while (stacks->list_b != 0)
	{
		is_max_min(stacks, 1, 1);
		if (stacks->list_b->content < stacks->value->min_a)
			new_order_min_stack(stacks, 1);
		else if (stacks->list_b->content > stacks->value->max_a)
		{
			new_order_max_stack(stacks, 1);
			rotate_a(&stacks->list_a);
		}
		else
			new_elem_in_a(stacks, stacks->list_b);
	}
	is_max_min(stacks, 1, 0);
	new_order_min_stack(stacks, 0);
}
