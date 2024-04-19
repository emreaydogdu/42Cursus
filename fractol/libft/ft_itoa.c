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


static size_t	ft_itoa_len(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num >= 1)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static char	*ft_itoa2(long num, char *str, size_t len)
{
	str = ft_callocc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (--len)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	if (str[0] != '-')
		str[0] = (num % 10) + '0';
	return (str);
}

char	*ft_itoa_h(long num)
{
	char	*str;

	str = 0;
	str = ft_itoa2(num, str, ft_itoa_len(num));
	if (!str)
		return (NULL);
	return (str);
}

