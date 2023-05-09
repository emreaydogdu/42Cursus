/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:55:00 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/08 17:55:31 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	numlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*a;
	size_t	len;
	long	nb;

	nb = n;
	len = numlen(n);
	a = malloc(sizeof(char) * (len + 1));
	if (a == 0)
		return (NULL);
	if (nb < 0)
	{
		a[0] = '-';
		nb = -nb;
	}
	a[len--] = '\0';
	if (nb == 0)
		a[0] = '0';
	while (nb)
	{
		a[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (a);
}
