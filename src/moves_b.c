/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:08:51 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/17 00:05:09 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	max_min_in_b(t_stack *stacks)
{
	int	index;
	int size;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	if (stacks->list_b->content == stacks->value->max_b)
		return ;
	index = find_index(stacks->list_b, stacks->value->max_b);
	size = stack_size(stacks->list_b);
	if (size % 2 == 0)
	{
		if (index + 1 > size / 2)
			stacks->moves->rrb = (size - index);
		else
			stacks->moves->rb = index;
	}
	else
	{
		if (index > size / 2)
			stacks->moves->rrb = (size - index);
		else
			stacks->moves->rb = index;
	}
}

void	new_elem_in_b(t_stack *stacks, t_linked_list *stack_a)
{
	int	index;
	int	search;
	int	size;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	search = search_number_stack_b(stacks->list_b, stack_a->content);
	if (stacks->list_b->content == search)
		return ;
	index = find_index(stacks->list_b, search);
	size = stack_size(stacks->list_b);
	if (size % 2 == 0)
	{
		if (index + 1 > size / 2)
			stacks->moves->rrb = (size - index);
		else
			stacks->moves->rb = index;
	}
	else
	{
		if (index > size / 2)
			stacks->moves->rrb = size - index;
		else
			stacks->moves->rb = index;
	}
}

void	to_top_stack_a(t_stack *stacks, t_linked_list *stack_a, int i)
{
	int size;
	stacks->moves->pb = 1;
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->list_a->content == stack_a->content)
		return ;
	size = stack_size(stacks->list_a);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->moves->rra = (size - i);
		else
			stacks->moves->ra = i;
	}
	else
	{
		if (i > size / 2)
			stacks->moves->rra = size - i;
		else
			stacks->moves->ra = i;
	}
}
