/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:31:04 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/10 23:46:12 by emaydogd         ###   ########.fr       */
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
	{
		pb(&a, &b);
		pb(&a, &b);
		ft_sort_big(&a, &b);
	}
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

void	print_list(int *lst)
{
	int	size;

	printf("List:	");
	size = 0;
	while (lst[size])
		printf("[%d]", lst[size++]);
	printf("\n");
}

void	ft_sort_big(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	val;
	int	*lst;
	int	*best;

	while (a->size)
	{
		best = calloc(sizeof(int), a->size + b->size);
		if (!best)
			return ;
		i = 0;
		while (i < a->size)
		{
			val = ft_getval(*a, i);
			j = 0;
			lst = calloc(sizeof(int), a->size + b->size);
			if (!lst)
				return ;
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
			//lst = ft_lstoptimize(lst, (a->size + b->size + 1));
			if (ft_lstlen(lst) < ft_lstlen(best) || !ft_lstlen(best))
				ft_memcpy(best, lst, ft_lstlen(lst));
			i++;
			free(lst);
		}
		ft_exec(best, a, b);
		free(best);
	}
	ft_rotate_end(*a, *b);
}
