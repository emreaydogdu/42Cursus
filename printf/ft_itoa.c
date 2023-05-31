/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:25:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/26 14:00:42 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

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

static char	*ft_itoa(long num, char *str, size_t len)
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
	str = ft_itoa(num, str, ft_itoa_len(num));
	if (!str)
		return (NULL);
	return (str);
}
