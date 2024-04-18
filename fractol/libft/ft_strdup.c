/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:54:40 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/09 15:54:41 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int				i;
	unsigned char	*ans;

	i = ft_strlen(s);
	ans = (unsigned char *)malloc(sizeof(unsigned char) * i + 1);
	if (!ans)
		return (0);
	ft_memcpy((char *)ans, s, i);
	ans[i] = '\0';
	return ((char *)ans);
}
