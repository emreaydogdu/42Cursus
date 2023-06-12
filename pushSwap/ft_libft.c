/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:32:49 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/12 20:02:47 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_abs(int val)
{
	if (val < 0)
		return (val * -1);
	return (val);
}

void	ft_split_ps(char *args, t_stack *a)
{
	int	val;

	val = 0;
	while (*args)
	{
		if (*args != ' ')
			val = val * 10 + *args - '0';
		else
		{
			add_stack(a, val);
			r(*a);
			val = 0;
		}
		args++;
	}
	add_stack(a, val);
	r(*a);
}

void	ft_exec(int *lst, t_stack *a, t_stack *b)
{
	while (*lst)
	{
		if (*lst == SA)
			sa(a);
		if (*lst == SB)
			sb(a);
		if (*lst == SS)
			ss(a, b);
		if (*lst == PA)
			pa(a, b);
		if (*lst == PB)
			pb(a, b);
		if (*lst == RA)
			ra(*a);
		if (*lst == RB)
			rb(*b);
		if (*lst == RR)
			rr(*a, *b);
		if (*lst == RRA)
			rra(*a);
		if (*lst == RRB)
			rrb(*b);
		if (*lst++ == RRR)
			rrr(*a, *b);
	}
}

void	ft_exec_b(const char *opt, t_stack *a, t_stack *b)
{
	if (ft_strncmp(opt, "sa", 3) == 0)
		sa(a);
	if (ft_strncmp(opt, "sb", 3) == 0)
		sb(a);
	if (ft_strncmp(opt, "ss", 3) == 0)
		ss(a, b);
	if (ft_strncmp(opt, "pa", 3) == 0)
		pa(a, b);
	if (ft_strncmp(opt, "pb", 3) == 0)
		pb(a, b);
	if (ft_strncmp(opt, "ra", 3) == 0)
		ra(*a);
	if (ft_strncmp(opt, "rb", 3) == 0)
		rb(*b);
	if (ft_strncmp(opt, "rr", 3) == 0)
		rr(*a, *b);
	if (ft_strncmp(opt, "rra", 3) == 0)
		rra(*a);
	if (ft_strncmp(opt, "rrb", 3) == 0)
		rrb(*b);
	if (ft_strncmp(opt, "rrr", 3) == 0)
		rrr(*a, *b);
}
