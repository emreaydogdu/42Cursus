/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoitoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <emaydogd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:19:54 by emaydogd          #+#    #+#             */
/*   Updated: 2024/06/24 18:46:47 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philosophers.h"

static int	ft_getlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_reverse_str(char *str)
{
	int		begin;
	int		end;
	char	temp;

	begin = 0;
	end = ft_strlen(str) - 1;
	while (begin < end)
	{
		temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;
		begin++;
		end--;
	}
}

char	*ft_itoa(int n)
{
	char			*ret;
	int				i;
	unsigned int	tmp_nbr;

	i = 0;
	ret = malloc(sizeof(*ret) * (ft_getlen(n) + 1));
	if (!ret)
		return (NULL);
	if (n < 0)
		tmp_nbr = -1 * n;
	else
		tmp_nbr = n;
	while (tmp_nbr != 0)
	{
		ret[i++] = (tmp_nbr % 10) + '0';
		tmp_nbr /= 10;
	}
	if (n == 0)
		ret[i++] = '0';
	if (n < 0)
		ret[i++] = '-';
	ret[i] = '\0';
	ft_reverse_str(ret);
	return (ret);
}

static int	ft_isdigit(int c)
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
	while (str[i] != '\0'){
		if (ft_isdigit(str[i]))
			res = res * 10 + (str[i] - '0');
		else if (!ft_isdigit(str[i]) && str[i] != '\0')
			return (-1);
		i++;
	}
	return (res * sign);
}
