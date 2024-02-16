/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:33:08 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/04 19:40:58 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_linked_list	*ft_new_a_node(int content)
{
	t_linked_list	*ptr;

	ptr = (t_linked_list *)malloc(sizeof(t_linked_list));
	if (ptr == 0)
		return (0);
	ptr->content = content;
	ptr->next = 0;
	return (ptr);
}

t_linked_list	*ft_str_to_a_list(char **str)
{
	int				i;
	int				counter;
	t_linked_list	*ptr;
	t_linked_list	*tmp;

	i = 0;
	counter = 0;
	str = ft_split(str[1], ' ');
	comprobation(2, str, NULL);
	is_repeated(2, str);
	while (str[i] != NULL)
	{
		i++;
		counter++;
	}
	i = 0;
	ptr = ft_new_a_node(ft_atoi(str[i]));
	tmp = ptr;
	while (++i < counter)
	{
		tmp->next = ft_new_a_node(ft_atoi(str[i]));
		tmp = tmp->next;
		tmp->next = NULL;
	}
	return (ptr);
}

t_linked_list	*ft_new_a_list(int argc, char **argv)
{
	int				i;
	int				j;
	t_linked_list	*ptr;
	t_linked_list	*tmp;

	i = 1;
	j = 0;
//	if (argc == 2)
//		ptr = ft_str_to_a_list(argv);
//	else
//	{
		j = argc;
		ptr = ft_new_a_node(ft_atoi(argv[i]));
		tmp = ptr;
		while (++i < j)
		{
			tmp->next = ft_new_a_node(ft_atoi(argv[i]));
			tmp = tmp->next;
			tmp->next = NULL;
		}
//	}
	return (ptr);
}

void	show_stack(t_linked_list *stack)
{
	t_linked_list	*temp;

	temp = stack;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}
}

int	stack_size(t_linked_list *lst)
{
	int		i;

	i = 0;
	if (lst == 0)
		return (0);
	while (lst != 0)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
