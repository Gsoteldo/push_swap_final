/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:25:28 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/13 19:26:33 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	is_max_a(t_stack *stacks, t_linked_list *stack_a)
{
	int	size_stack;
	int	i;

	i = 0;
	size_stack = stack_size(stack_a);
	stacks->value = (t_value *)malloc(sizeof(t_value));
	stacks->value->max_a = stack_a->content;
	while (i < size_stack)
	{
		if (stacks->value->max_a < stack_a->content)
			stacks->value->max_a = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
}

static void	is_min_a(t_stack *stacks, t_linked_list *stack_a)
{
	int	size_stack;
	int	i;

	i = 0;
	size_stack = stack_size(stacks->list_a);
	stacks->value->min_a = stack_a->content;
	while (i < size_stack)
	{
		if (stacks->value->min_a > stack_a->content)
			stacks->value->min_a = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
}

static void	is_max_b(t_stack *stacks, t_linked_list *stack_b)
{
	int	size_stack;
	int	i;

	i = 0;
	size_stack = stack_size(stack_b);
	stacks->value->max_b = stack_b->content;
	while (i < size_stack)
	{
		if (stacks->value->max_b < stack_b->content)
			stacks->value->max_b = stack_b->content;
		stack_b = stack_b->next;
		i++;
	}
}

static void	is_min_b(t_stack *stacks, t_linked_list *stack_b)
{
	int	size_stack;
	int	i;

	i = 0;
	size_stack = stack_size(stack_b);
	stacks->value->min_b = stack_b->content;
	while (i < size_stack)
	{
		if (stacks->value->min_b > stack_b->content)
			stacks->value->min_b = stack_b->content;
		stack_b = stack_b->next;
		i++;
	}
}

void	is_max_min(t_stack *stacks, int flag_a, int flag_b)
{
	if (flag_a ==1)
	{
	is_max_a(stacks, stacks->list_a);
	is_min_a(stacks, stacks->list_a);
	}
	if (flag_b == 1)
	{
		is_max_b(stacks, stacks->list_b);
		is_min_b(stacks, stacks->list_b);
	}
}
