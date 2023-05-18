/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:09:10 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/18 18:25:51 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	ssize_t	i;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (ft_nlchr(str) && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_splitfrst(str);
	str = ft_splitscnd(str);
	return (line);
}

/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("../getNextLine/file", O_RDONLY);
	while (line = get_next_line(fd))
		printf("%s", line);
	close(fd);
	printf("\n\nBUFFER -> %d\n\n", BUFFER_SIZE);
	return (0);
}
*/