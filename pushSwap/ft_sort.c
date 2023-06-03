/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:31:04 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/03 12:01:45 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
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

int	ft_calc(t_stack a, t_stack b, int *lst)
{
	int		i;
	int		j;
	int		k;
	int		minn;
	int		maxx;
	t_node	*min;
	t_node	*max;
	t_node	*use;

	i = 0;
	minn = 0;
	maxx = 0;
	while (i < a.size)
	{
		j = 0;
		if (a.size - 1 - i >= a.size / 2)
		{
			while (j != i && i != a.size - 1)
				lst[j++] = RA;
		}
		else
		{
			while (a.size - 1 - i - j != 0)
				lst[j++] = RRA;
			lst[j++] = RRA;
		}

		min = ft_find_min(b);
		max = ft_find_max(b);
		if (a.stack->val > min->val && a.stack->val < max->val)
		{
			max = ft_find_next(a.stack->val, b);
			min = ft_find_prev(a.stack->val, b);
			if (min->idx >= b.size / 2)
				minn = b.size - 1 - min->idx;
			else
				minn = b.size - 1 - min->idx;
			if (max->idx >= b.size / 2)
				maxx = b.size - 1 - max->idx + 1;
			else
				maxx = max->idx;
			use = min;
			if (minn > maxx)
				use = max;
		}
		if (a.stack->val > use->val && use->idx >= b.size / 2)
		{
			k = use->idx;
			while (k++ != b.size - 1)
				lst[j++] = RB;
		}
		else if (a.stack->val > use->val)
		{
			k = max->idx;
			while (k-- != 0)
				lst[j++] = RRB;
			lst[j++] = RRB;
		}
		i++;
		lst[j++] = PB;
		/*
		if (a->stack->val > max->val)
		{
			if (max->idx >= b->size / 2)
			{
				k = max->idx;
				while (k-- != 0)
					lst[j++] = RRB;
				lst[j++] = RRB;
			}
			else
			{
				k = max->idx;
				while (k++ != b->size - 1)
					lst[j++] = RB;
			}
		}
		else if (a->stack->val < min->val)
		{
			if (min->idx > b->size / 2)
			{
				k = min->idx;
				while (k++ != b->size - 1)
					lst[j++] = RB;
				lst[j++] = RB;
			}
			else
			{
				k = min->idx;
				while (k-- != 0)
					lst[j++] = RRB;
			}
		}
		lst[j++] = PA;
		while (*lst)
			printf("[%d]", *lst++);
		printf("\n\n");
		i++;
		*/
		a.stack = a.stack->next;
	}
	return (0);
}

int	ft_lstlen(const int *lst)
{
	int	len;

	len = 0;
	while (lst[len] && lst[len] != -1)
		len++;
	return (len);
}

void	ft_lstprint(const int *lst)
{
	int	len;

	len = 0;
	while (lst[len])
		printf("[%d]", lst[len++]);
	printf("\n");
}

void	ft_lstreset(int *lst)
{
	int i;

	i = 0;
	while (lst[i])
		lst[i++] = -1;
}

void	ft_lstcpy(const int *lst, int *best)
{
	int i;

	i = -1;
	while (lst[i++])
		best[i] = lst[i];
}

int		ft_getval(t_stack a, int i)
{
	while (i--)
		a.stack = a.stack->next;
	return (a.stack->val);
}

void	ft_place_new_min(t_stack a, t_stack b, int *lst, int j)
{
	t_node	*min;
	int		k;

	min = ft_find_min(b);
	if (ft_abs(b.size - 1 - min->idx) + 1 <= min->idx)
	{
		k = min->idx;
		while (k++ < b.size - 1)
			lst[j++] = RB;
		lst[j++] = RB;
	}
	else
	{
		k = min->idx;
		while (k-- > 0)
			lst[j++] = RRB;
	}
	lst[j++] = PB;
}

void	ft_place_new_max(t_stack a, t_stack b, int *lst, int j)
{
	t_node	*max;
	int		k;

	max = ft_find_max(b);
	if (ft_abs(b.size - 1 - max->idx) <= max->idx + 1)
	{
		k = max->idx;
		while (k++ < b.size - 1)
			lst[j++] = RB;
	}
	else
	{
		k = max->idx;
		while (k-- > 0)
			lst[j++] = RRB;
		lst[j++] = RRB;
	}
	lst[j++] = PB;
}

void	ft_place_new_middle(t_stack a, t_stack b, int val, int *lst, int j)
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

void	ft_sort_big(t_stack *a, t_stack *b)
{
	int i;
	int j;
	int val;
	int *lst;
	int *best;
	best = malloc(sizeof(int) * 100);
	if (!best)
		return;

	pb(a, b);
	pb(a, b);
	i = 0;
	while (a->size)
	{
		i = 0;
		while (i < a->size)
		{
			val = ft_getval(*a, i);
			j = 0;
			lst = malloc(sizeof(int) * 100);
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
				ft_place_new_min(*a, *b, lst, j);
			else if (val > ft_find_max(*b)->val)
				ft_place_new_max(*a, *b, lst, j);
			else
				ft_place_new_middle(*a, *b, val, lst, j);
			if (ft_lstlen(lst) < ft_lstlen(best) || !ft_lstlen(best))
				best = lst;
			i++;
		}
		ft_exec(best, a, b);
		ft_lstreset(best);
	}
	ft_lstreset(lst);
	ft_place_new_max(*a, *b, lst, j);
	ft_exec(lst, a, b);
	while (b->size)
		pa(a, b);
	print_stack(*a);
	print_stack(*b);
}