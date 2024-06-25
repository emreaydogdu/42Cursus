/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:50:19 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/13 01:02:45 by emaydogd         ###   ########.fr       */
/*                                                                            */
#include <printf.h>

/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
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
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

int	main(void)
{
	return (printf("%d\n", ft_atoi("2345")),printf("%d", ft_atoi("1234")), 0);
}
