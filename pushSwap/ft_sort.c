/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:31:04 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/05 15:10:02 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_sort(t_stack a, t_stack b)
{
	if (a.size == 2)
		if (a.stack->val > a.stack->next->val)
			sa(&a);
	if (a.size == 3)
		ft_sort3(&a);
	else if (a.size == 4)
		ft_sort4(&a, &b);
	else if (a.size == 5)
		ft_sort5(&a, &b);
	else if (a.size > 5)
		ft_sort_big(&a, &b);
}

void	ft_sort3(t_stack *a)
{
	int	frst;
	int	scnd;
	int	thrd;

	frst = a->stack->val;
	scnd = a->stack->next->val;
	thrd = a->stack->next->next->val;
	if (frst > scnd && thrd > scnd && frst < thrd)
		sa(a);
	else if (frst > scnd && thrd > scnd && frst > thrd)
		ra(*a);
	else if (frst < scnd && thrd < scnd && frst > thrd)
		rra(*a);
	else if (frst > scnd && thrd < scnd && frst > thrd)
	{
		sa(a);
		rra(*a);
	}
	else if (frst < scnd && thrd < scnd && frst < thrd)
	{
		sa(a);
		ra(*a);
	}
}

void	ft_sort4(t_stack *a, t_stack *b)
{
	pb(a, b);
	ft_sort3(a);
	if (b->stack->val < a->stack->val)
		pa(a, b);
	else if (b->stack->val < a->stack->next->val)
	{
		ra(*a);
		pa(a, b);
		rra(*a);
	}
	else if (b->stack->val < a->stack->next->next->val)
	{
		rra(*a);
		pa(a, b);
		ra(*a);
		ra(*a);
	}
	else
	{
		pa(a, b);
		ra(*a);
	}
}

void	ft_sort5(t_stack *a, t_stack *b)
{
	t_node	*min_idx;

	min_idx = ft_find_min(*a);
	while (a->stack->val != min_idx->val)
	{
		if (min_idx->idx < a->size / 2)
			rra(*a);
		else
			ra(*a);
		min_idx = ft_find_min(*a);
	}
	pb(a, b);
	min_idx = ft_find_min(*a);
	while (a->stack->val != min_idx->val)
	{
		if (min_idx->idx < a->size / 2)
			rra(*a);
		else
			ra(*a);
		min_idx = ft_find_min(*a);
	}
	pb(a, b);
	ft_sort3(a);
	pa(a, b);
	pa(a, b);
}

void	ft_exec(int *lst, t_stack *a, t_stack *b)
{
	while(*lst)
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
		if (*lst == RRR)
			rrr(*a, *b);
		lst++;
	}
}

void	ft_check_min(t_stack b, int val, int *lst, int j)
{
	t_node	*prev;
	int		k;

	prev = ft_find_prev(val, b);
	if (ft_abs(b.size - 1 - prev->idx) <= prev->idx + 1)
	{
		k = prev->idx;
		while (k++ < b.size - 1)
			lst[j++] = RB;
	}
	else
	{
		k = prev->idx;
		while (k-- > 0)
			lst[j++] = RRB;
		lst[j++] = RRB;
	}
	lst[j++] = PB;
}
void	ft_check_max(t_stack b, int val, int *lst, int j)
{
	t_node	*next;
	int		k;

	next = ft_find_next(val, b);
	//printf("[%d]-[%d]\n", val, next->val);
	if (ft_abs(b.size - 1 - next->idx) <= next->idx + 1)
	{
		k = next->idx;
		while (k++ < b.size - 1)
			lst[j++] = RB;
		lst[j++] = RB;
	}
	else
	{
		k = next->idx;
		while (k-- > 0)
			lst[j++] = RRB;
		//lst[j++] = RRB;
	}
	lst[j++] = PB;
}

int	*ft_place_new_middle(t_stack b, int val, int *lst, int j)
{
	ft_check_min(b, val, lst, j);
	//ft_check_max(b, val, lst, j);
	//ft_lstprint(lst);
	return (lst);
}

void	ft_sort_big(t_stack *a, t_stack *b)
{
	int i;
	int j;
	int val;
	int *lst;
	int *best;
	best = malloc(sizeof(int) * 1000);
	if (!best)
		return;

	pb(a, b);
	pb(a, b);
	while (a->size)
	{
		i = 0;
		while (i < a->size)
		{
			val = ft_getval(*a, i);
			j = 0;
			lst = malloc(sizeof(int) * 1000);
			if (!lst)
				return;
			if (a->size - 1 - i >= a->size / 2)
			{
				while (j != i && i != a->size - 1)
					lst[j++] = RA;
			}
			else
			{
				while (a->size - 1 - i - j != 0)
					lst[j++] = RRA;
				lst[j++] = RRA;
			}
			if (val < ft_find_min(*b)->val)
				ft_place_new_min(*b, lst, j);
			else if (val > ft_find_max(*b)->val)
				ft_place_new_max(*b, lst, j);
			else
				lst = ft_place_new_middle(*b, val, lst, j);
			lst = ft_lstoptimize(lst);
			//ft_lstprint(lst);
			if (ft_lstlen(lst) < ft_lstlen(best) || !ft_lstlen(best))
				best = lst;
			i++;
		}
		ft_exec(best, a, b);
		ft_lstreset(best);
	}
	ft_lstreset(lst);
	j = 0;
	ft_rotate_end(*b, lst, j);
	ft_exec(lst, a, b);
	while (b->size)
		pa(a, b);
	//print_stack(*a);
	//print_stack(*b);
}