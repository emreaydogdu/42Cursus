/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:44:07 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/28 21:55:53 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
	int				val;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	int		empty;
	int		size;
	t_node	*stack;
}	t_stack;


void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack a);
void	rb(t_stack b);
void	rr(t_stack a, t_stack b);
void	rra(t_stack a);
void	rrb(t_stack b);
void	rrr(t_stack a, t_stack b);

void	init_stack(t_stack *stack);
void	print_stack(t_stack stack);
void	add_stack(t_stack *stack, int val);
void	rm_stack(t_stack *stack);

#endif //PUSH_SWAP_H
