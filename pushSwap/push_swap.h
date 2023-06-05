/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:44:07 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/05 02:23:23 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

# define SA   0
# define SB   1
# define SS   2
# define PA   3
# define PB   4
# define RA   5
# define RB   6
# define RR   7
# define RRA  8
# define RRB  9
# define RRR 10

typedef struct s_node {
	int				idx;
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
void	r(t_stack s);
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

void	ft_sort(t_stack a, t_stack b);
void	ft_sort3(t_stack *a);
void	ft_sort4(t_stack *a, t_stack *b);
void	ft_sort5(t_stack *a, t_stack *b);
void	ft_sort_big(t_stack *a, t_stack *b);
int		ft_abs(int val);
t_node	*ft_find_min(t_stack a);
t_node	*ft_find_max(t_stack a);
t_node	*ft_find_next(int val, t_stack s);
t_node	*ft_find_prev(int val, t_stack s);

void	ft_place_new_min(t_stack b, int *lst, int j);
void	ft_place_new_max(t_stack b, int *lst, int j);
void	ft_rotate_end(t_stack b, int *lst, int j);

int		ft_lstlen(const int *lst);
void	ft_lstprint(const int *lst);
void	ft_lstreset(int *lst);
int		*ft_lstoptimize(int *lst);
int		ft_getval(t_stack a, int i);

#endif //PUSH_SWAP_H
