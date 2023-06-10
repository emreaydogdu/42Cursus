/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:02:50 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/10 16:14:43 by emaydogd         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (lst[i])
		lst[i++] = -1;
}

int	ft_getval(t_stack a, int i)
{
	while (i--)
		a.stack = a.stack->next;
	return (a.stack->val);
}

void	ft_initopt(t_optimize	*opt)
{
	opt->ra = 0;
	opt->rb = 0;
	opt->rr = 0;
	opt->rra = 0;
	opt->rrb = 0;
	opt->rrr = 0;
}

int	*ft_lstoptimize(int *lst)
{
	int			*l;
	int			count;
	int			i;
	int			j;
	t_optimize	opt;

	i = 0;
	count = 0;
	ft_initopt(&opt);
	while (lst[i])
	{
		if (lst[i] == RA)
			opt.ra++;
		if (lst[i] == RB)
			opt.rb++;
		if (ra > 0 && rb > 0)
		{
			opt.ra--;
			opt.rb--;
			opt.rr++;
		}
		if (lst[i] == RRA)
			opt.rra++;
		if (lst[i++] == RRB)
			opt.rrb++;
		if (rra > 0 && rrb > 0)
		{
			opt.rra--;
			opt.rrb--;
			opt.rrr++;
		}
		count++;
	}
	l = malloc(sizeof(int) * 10000);
	if (!l)
		return (lst);
	i = 0;
	j = opt.ra + opt.rra + opt.rrr * 2 + opt.rr * 2 + opt.rb + opt.rrb;
	while (opt.ra-- > 0)
		l[i++] = RA;
	while (opt.ra-- > 0)
		l[i++] = RA;
	while (opt.rra-- > 0)
		l[i++] = RRA;
	while (opt.rr-- > 0)
		l[i++] = RR;
	while (opt.rrr-- > 0)
		l[i++] = RRR;
	while (opt.rb-- > 0)
		l[i++] = RB;
	while (opt.rrb-- > 0)
		l[i++] = RRB;
	while (lst[j])
		l[i++] = lst[j++];
	return (lst);
}
