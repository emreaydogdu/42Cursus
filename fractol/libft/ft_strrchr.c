/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:13:56 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/09 16:13:57 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_endl(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return ((char *)s + i);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*buf;

	if (!s)
		return (0);
	buf = (char *)s;
	i = ft_strlen(s) - 1;
	if ((unsigned char)c == 0)
		return (ft_endl(s));
	while (i >= 0)
	{
		if ((unsigned char)buf[i] == (unsigned char)c)
			return (&buf[i]);
		i--;
	}
	return (0);
}
