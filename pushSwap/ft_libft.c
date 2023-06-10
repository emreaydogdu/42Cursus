/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:32:49 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/09 18:47:36 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_abs(int val)
{
	if (val < 0)
		return (val * -1);
	return (val);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

int	*ft_memset(int *b, int c, size_t len)
{
	while (len--)
		((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = n;
	if (!(dst || src))
		return (NULL);
	while (n--)
		*(char *)dst++ = *(char *)src++;
	return (dst - i);
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
