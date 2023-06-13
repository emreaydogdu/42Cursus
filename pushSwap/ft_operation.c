/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:31:08 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/13 21:07:10 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ft_initopt(t_optimize *opt)
{
	opt->ra = 0;
	opt->rb = 0;
	opt->rr = 0;
	opt->rra = 0;
	opt->rrb = 0;
	opt->rrr = 0;
}

static void	ft_calcopt(const int *lst, t_optimize *opt, int i)
{
	while (lst[i])
	{
		if (lst[i] == RA)
			opt->ra++;
		if (lst[i] == RB)
			opt->rb++;
		if (opt->ra > 0 && opt->rb > 0)
		{
			opt->ra--;
			opt->rb--;
			opt->rr++;
		}
		if (lst[i] == RRA)
			opt->rra++;
		if (lst[i++] == RRB)
			opt->rrb++;
		if (opt->rra > 0 && opt->rrb > 0)
		{
			opt->rra--;
			opt->rrb--;
			opt->rrr++;
		}
	}
}

void	ft_optimize(int *lst)
{
	int			i;
	t_optimize	opt;

	i = 0;
	ft_initopt(&opt);
	ft_calcopt(lst, &opt, i);
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
