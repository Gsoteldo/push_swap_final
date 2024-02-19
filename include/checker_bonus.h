/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:52:08 by gabo              #+#    #+#             */
/*   Updated: 2024/02/17 18:01:20 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct t_linked_list
{
	int						content;
	struct t_linked_list	*next;
}	t_linked_list;

typedef struct t_stack
{
	struct t_linked_list	*list_a;
	struct t_linked_list	*list_b;
	struct t_moves			*cheapest;
	struct t_moves			*moves;
	struct t_value			*value;
}	t_stack;

typedef struct t_value
{
	int				max_a;
	int				max_b;
	int				min_a;
	int				min_b;
}	t_value;

typedef struct t_moves
{
	int	moves;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;	
	int	sa;
	int	sb;
	int	ss;
}	t_moves;

#endif