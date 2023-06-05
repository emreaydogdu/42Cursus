/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:02:50 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/05 02:09:41 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

int		ft_getval(t_stack a, int i)
{
	while (i--)
		a.stack = a.stack->next;
	return (a.stack->val);
}

int	*ft_lstoptimize(int *lst)
{
	int *l;
	int count = 0;
	int	i = 0;
	int	j;
	int	ra = 0;
	int	rb = 0;
	int	rr = 0;
	int	rra = 0;
	int	rrb = 0;
	int	rrr = 0;

	while (lst[i])
	{
		if (lst[i] == RA)
			ra++;
		if (lst[i] == RB)
			rb++;
		if (ra > 0 && rb > 0)
		{
			ra--;
			rb--;
			rr++;
		}
		if (lst[i] == RRA)
			rra++;
		if (lst[i++] == RRB)
			rrb++;
		if (rra > 0 && rrb > 0)
		{
			rra--;
			rrb--;
			rrr++;
		}
		count++;
	}
	l = malloc(sizeof(int) * 10000);
	if (!l)
		return lst;
	i = 0;
	j = ra + rra + rrr * 2 + rr * 2 + rb + rrb;
	while (ra--)
		l[i++] = RA;
	while (rra--)
		l[i++] = RRA;
	while (rr--)
		l[i++] = RR;
	while (rrr--)
		l[i++] = RRR;
	while (rb--)
		l[i++] = RB;
	while (rrb--)
		l[i++] = RRB;
	while (lst[j])
		l[i++] = lst[j++];
	return (l);
}