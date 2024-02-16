/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:59:36 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/02 17:43:08 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	r_rotate(t_linked_list **stack)
{
	t_linked_list	*temp;
	t_linked_list	*temp2;

	if (stack == NULL)
		return ;
	temp = *stack;
	temp2 = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp2 = temp->next;
	temp->next = NULL;
	temp2->next = *stack;
	*stack = temp2;
}

void	r_rotate_a(t_linked_list **stack_a)
{
	r_rotate(stack_a);
	ft_printf("rra\n");
}

void	r_rotate_b(t_linked_list **stack_b)
{
	r_rotate(stack_b);
	ft_printf("rrb\n");
}

void	r_rotate_ab(t_linked_list **stack_a, t_linked_list **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	ft_printf("rrr\n");
}
