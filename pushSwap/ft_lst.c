/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:02:50 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/12 17:22:19 by emaydogd         ###   ########.fr       */
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

void	ft_lstreset(int *lst)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lstlen(lst);
	while (i < len)
	{
		lst[i] = 0;
		i++;
	}
}

t_node	*ft_getval(t_stack a, int i)
{
	while (i--)
		a.stack = a.stack->next;
	return (a.stack);
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

void	ft_lstoptimize(int *lst)
{
	int			i;
	t_optimize	opt;

	i = 0;
	ft_initopt(&opt);
	while (lst[i])
	{
		if (lst[i] == RA)
			opt.ra++;
		if (lst[i] == RB)
			opt.rb++;
		if (opt.ra > 0 && opt.rb > 0)
		{
			opt.ra--;
			opt.rb--;
			opt.rr++;
		}
		if (lst[i] == RRA)
			opt.rra++;
		if (lst[i++] == RRB)
			opt.rrb++;
		if (opt.rra > 0 && opt.rrb > 0)
		{
			opt.rra--;
			opt.rrb--;
			opt.rrr++;
		}
	}
	i = 0;
	ft_lstreset(lst);
	while (opt.ra-- > 0)
		lst[i++] = RA;
	while (opt.rra-- > 0)
		lst[i++] = RRA;
	while (opt.rr-- > 0)
		lst[i++] = RR;
	while (opt.rrr-- > 0)
		lst[i++] = RRR;
	while (opt.rb-- > 0)
		lst[i++] = RB;
	while (opt.rrb-- > 0)
		lst[i++] = RRB;
	lst[i++] = PB;
}
