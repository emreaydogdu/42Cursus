/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:26:03 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/12 17:26:04 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*ans;
	int				i;
	int				len_s1;
	int				len;

	i = 0;
	len_s1 = ft_strlen(s1);
	len = len_s1 + ft_strlen(s2) + 1;
	ans = (unsigned char *)malloc(sizeof(unsigned char) * len);
	if (!ans)
		return (0);
	while ((unsigned char)s1[i])
	{
		ans[i] = (unsigned char)s1[i];
		i++;
	}
	i = 0;
	while ((unsigned char)s2[i])
	{
		ans[i + len_s1] = (unsigned char)s2[i];
		i++;
	}
	ans[len_s1 + i] = '\0';
	return ((char *)ans);
}
