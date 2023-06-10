/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:44:07 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/10 22:18:20 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

# define SA   1
# define SB   2
# define SS   3
# define PA   4
# define PB   5
# define RA   6
# define RB   7
# define RR   8
# define RRA  9
# define RRB 10
# define RRR 11

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

typedef struct s_optimize {
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_optimize;

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
void	ft_check_max(t_stack b, int val, int *lst, int j);
int		*ft_place_new_middle(t_stack b, int val, int *lst, int j);
void	ft_exec(int *lst, t_stack *a, t_stack *b);

void	ft_place_new_min(t_stack b, int *lst, int j);
void	ft_place_new_max(t_stack b, int *lst, int j);
void	ft_rotate_end(t_stack a, t_stack b);
void	ft_initopt(t_optimize	*opt);

int		ft_lstlen(const int *lst);
void	ft_lstprint(const int *lst);
void	ft_lstreset(int *lst);
int		*ft_lstoptimize(int *lst, int size);
int		ft_getval(t_stack a, int i);

int		ft_atoi(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	print_list(int *lst);

#endif //PUSH_SWAP_H
