/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:28:01 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/16 23:51:02 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_cheapest(t_stack *stack)
{
	while (stack->cheapest->ra-- != 0)
		rotate_a(&stack->list_a);
	while (stack->cheapest->rb-- != 0)
		rotate_b(&stack->list_b);
	while (stack->cheapest->rr-- != 0)
		rotate_ab(&stack->list_a, &stack->list_b);
	while (stack->cheapest->rra-- != 0)
		r_rotate_a(&stack->list_a);
	while (stack->cheapest->rrb-- != 0)
		r_rotate_b(&stack->list_b);
	while (stack->cheapest->rrr-- != 0)
		r_rotate_ab(&stack->list_a, &stack->list_b);
	while (stack->cheapest->pb-- != 0)
		push_b(&stack->list_a, &stack->list_b);
}

void	double_moves_checker(t_stack *stacks)
{
	stacks->moves->rr = 0;
	stacks->moves->rrr = 0;
	while (stacks->moves->ra != 0 && stacks->moves->rb != 0)
	{
		stacks->moves->ra--;
		stacks->moves->rb--;
		stacks->moves->rr++;
	}
	while (stacks->moves->rra != 0 && stacks->moves->rrb != 0)
	{
		stacks->moves->rra--;
		stacks->moves->rrb--;
		stacks->moves->rrr++;
	}
}

void	cost(t_stack *stacks, int i)
{
	stacks->moves->moves = stacks->moves->ra + stacks->moves->rb
		+ stacks->moves->rr + stacks->moves->rra + stacks->moves->rrb
		+ stacks->moves->rrr + stacks->moves->pb;
	if (i == 1 || stacks->moves->moves < stacks->cheapest->moves)
	{
		stacks->cheapest->moves = stacks->moves->moves;
		stacks->cheapest->ra = stacks->moves->ra;
		stacks->cheapest->rb = stacks->moves->rb;
		stacks->cheapest->rr = stacks->moves->rr;
		stacks->cheapest->rra = stacks->moves->rra;
		stacks->cheapest->rrb = stacks->moves->rrb;
		stacks->cheapest->rrr = stacks->moves->rrr;
		stacks->cheapest->pb = stacks->moves->pb;
	}
}
		//stacks->cheapest->pa = stacks->moves->pa;
		//stacks->cheapest->sa = stacks->moves->sa;
		//stacks->cheapest->sb = stacks->moves->sb;
		//stacks->cheapest->ss = stacks->moves->ss;

void	move_checker(t_stack *stacks)
{
	t_linked_list	*aux;
	int				i;
	int size;

	aux = stacks->list_a;
	size = stack_size(stacks->list_a);
	i = 0;
	while (i++ < size)
	{
		to_top_stack_a(stacks, aux, i - 1);
		if (aux->content > stacks->value->max_b
			|| aux->content < stacks->value->min_b)
			max_min_in_b(stacks);
		else
			new_elem_in_b(stacks, aux);
		double_moves_checker(stacks);
		cost(stacks, i);
		aux = aux->next;
	}
}

void	cheapest(t_stack *stacks)
{
	//int size;

	//size = stack_size(stacks->list_a);
	stacks->moves = (t_moves *)ft_calloc(1, sizeof(t_moves));
	stacks->cheapest = (t_moves *)ft_calloc(1, sizeof(t_moves));
	stacks->value = (t_value *)ft_calloc(1, sizeof(t_value));
	while (stack_size(stacks->list_a) != 3)
	{
		is_max_min(stacks, 0, 1);
		move_checker(stacks);
		move_cheapest(stacks);
	}
}
