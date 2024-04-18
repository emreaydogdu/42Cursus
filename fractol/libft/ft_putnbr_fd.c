/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:58:28 by fzucconi          #+#    #+#             */
/*   Updated: 2023/11/22 19:17:36 by fzucconi         ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	char					ans[12];
	int						len;
	long long int			buf;

	buf = (long long int)n;
	if (buf < 0)
		len = lenght(buf) + 1;
	else
		len = lenght(buf);
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
	ft_putstr_fd((char *)ans, fd);
}
