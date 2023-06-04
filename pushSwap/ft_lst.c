/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:02:50 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/05 00:04:34 by emaydogd         ###   ########.fr       */
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