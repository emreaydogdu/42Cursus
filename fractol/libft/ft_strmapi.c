/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:06:21 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/12 19:06:22 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*ans;
	unsigned int		index;
	unsigned int		len;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	ans = (char *)malloc(sizeof(char) * len + 1);
	if (!ans)
		return (0);
	index = 0;
	while (s[index])
	{
		ans[index] = f(index, s[index]);
		index++;
	}
	ans[index] = '\0';
	return (ans);
}
