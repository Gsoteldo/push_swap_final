/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:51:23 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/13 19:11:02 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_and_rotate(t_linked_list **stack_a)
{
	swap_a(stack_a);
	rotate_a(stack_a);
}

static void	swap_and_reverse_rotate(t_linked_list **stack_a)
{
	swap_a(stack_a);
	r_rotate_a(stack_a);
}

void	sort_3_numbers(t_linked_list **stack_a)
{
	int	first_elem;
	int	second_elem;
	int	third_elem;

	first_elem = (*stack_a)->content;
	second_elem = (*stack_a)->next->content;
	third_elem = (*stack_a)->next->next->content;
	if ((first_elem > second_elem) && (second_elem < third_elem)
		&& (first_elem < third_elem))
		swap_a(stack_a);
	else if ((first_elem > second_elem) && (second_elem > third_elem)
		&& (first_elem > third_elem))
		swap_and_reverse_rotate(stack_a);
	else if ((first_elem > second_elem) && (second_elem < third_elem)
		&& (first_elem > third_elem))
		rotate_a(stack_a);
	else if ((first_elem < second_elem) && (second_elem > third_elem)
		&& (first_elem < third_elem))
		swap_and_rotate(stack_a);
	else if ((first_elem < second_elem) && (second_elem > third_elem)
		&& (first_elem > third_elem))
		r_rotate_a(stack_a);
}
