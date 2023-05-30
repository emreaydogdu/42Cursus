/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:31:04 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/29 16:43:22 by emaydogd         ###   ########.fr       */
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
	else if (a.size > 3)
		ft_sort_g(&a, &b);
	print_stack(a);
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

int	ft_find_min(t_stack a)
{
	int	min;

	min = 0;
	while (a.stack->next)
	{
		if (a.stack->val < min)
			min = a.stack->val;
		a.stack = a.stack->next;
	}
	if (a.stack->val < min)
		min = a.stack->val;
	return (min);
}

int	ft_find_max(t_stack a)
{
	int	max;

	max = 0;
	while (a.stack->next)
	{
		if (a.stack->val > max)
			max = a.stack->val;
		a.stack = a.stack->next;
	}
	if (a.stack->val > max)
		max = a.stack->val;
	return (max);
}

int	bits(unsigned long num)
{
	int	ret;

	ret = 0;
	while (num)
	{
		ret += 1;
		num >>= 1;
	}
	return (ret);
}

int	digits(int n)
{
	int	ret;

	ret = 0;
	while (n)
	{
		ret += 1;
		n /= 10;
	}
	return (ret);
}

int digit(int n, int i)
{
	while (i--)
		n /= 10;
	return (n % 10);
}

void	ft_parse_stack(t_stack a)
{
	int	min;

	min = ft_find_min(a);
	if (min < 0)
	{
		min *= -1;
		while (a.stack->next)
		{
			a.stack->val += min;
			a.stack = a.stack->next;
		}
		a.stack->val += min;
	}
}

void	ft_sort_g(t_stack *a, t_stack *b)
{
	int	stack_size;
	int	max;
	int	size;
	int	i;
	int	j;

	ft_parse_stack(*a);
	max = ft_find_max(*a);
	size = digits(max);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 10)
		{
			stack_size = a->size;
			while (stack_size-- > 0)
			{
				if (digit(a->stack->val, i) == j)
					pb(a, b);
				else
					ra(*a);
			}
			j++;
		}
		while (b->stack)
			pa(a, b);
		i++;
	}
}

/*
void	ft_sort_g(t_stack *a, t_stack *b)
{
	int	stack_size;
	int	max;
	int	size;
	int	i;

	ft_parse_stack(*a);
	max = ft_find_max(*a);
	size = bits(max);
	i = 0;
	while (i < size)
	{
		stack_size = a->size;
		while (stack_size-- > 0)
		{
			if ((a->stack->val >> i & 1) == 0)
				pb(a, b);
			else
				ra(*a);
		}
		while (b->stack)
			pa(a, b);
		i++;
	}
}
 */