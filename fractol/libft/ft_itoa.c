/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:56:39 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/16 11:56:43 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lenght(long long int n)
{
	size_t	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char			*ans;
	int				len;
	long long int	buf;

	buf = (long long int)n;
	if (buf < 0)
		len = lenght(buf) + 1;
	else
		len = lenght(buf);
	ans = (char *)malloc(sizeof(char) * len + 1);
	if (!ans)
		return (0);
	if (buf < 0)
		buf *= -1;
	ans[len--] = 0;
	while (len >= 0)
	{
		ans[len--] = (buf % 10) + '0';
		buf /= 10;
	}
	if (n < 0)
		ans[0] = '-';
	return (ans);
}
