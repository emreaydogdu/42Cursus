/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:25:30 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/08 16:24:00 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;

	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		join[i] = *s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		join[i] = *s2++;
		i++;
	}
	join[i] = '\0';
	return (join);
}
/*
#include <stdio.h>
int	main(void)
{
	char **strs = malloc(sizeof(int)*2);
	strs[0] = "Hello";
	strs[1] = "World";
	char *res = ft_strjoin(2, strs, "-||-");
	printf("%s", res);
	free(strs);
	free(res);
	return (0);
}
*/
