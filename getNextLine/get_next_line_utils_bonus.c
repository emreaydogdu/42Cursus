/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:53:36 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/18 18:22:32 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_nlchr(char *str)
{
	if (!str)
		return (1);
	while (*str)
		if (*str++ == '\n')
			return (0);
	return (1);
}

char	*ft_strjoin(char *str, char *buf)
{
	int		i;
	int		j;
	char	*join;

	i = -1;
	j = 0;
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	join = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buf)) + 1));
	if (!join)
		return (NULL);
	while (str[++i])
		join[i] = str[i];
	while (buf[j])
		join[i++] = buf[j++];
	join[i] = '\0';
	free(str);
	return (join);
}

char	*ft_splitfrst(const char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_splitscnd(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!line)
		return (NULL);
	i = i + 1;
	while (str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	free(str);
	return (line);
}
