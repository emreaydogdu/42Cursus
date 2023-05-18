/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:09:10 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/18 21:12:27 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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
	static char	*str[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_splitfrst(str[fd]);
	str[fd] = ft_splitscnd(str[fd]);
	return (line);
}

/*
int	main(void)
{
	int		fd1;
	int		fd2;

	fd1 = open("../getNextLine/file", O_RDONLY);
	fd2 = open("../getNextLine/file_bonus", O_RDONLY);
	printf("[%d] || [%d]\n", fd1, fd2);
	printf("[%s] || [%s]", get_next_line(fd1), get_next_line(fd2));
	printf("[%s] || [%s]", get_next_line(fd1), get_next_line(fd2));
	printf("[%s] || [%s]", get_next_line(fd1), get_next_line(fd2));
	close(fd1);
	close(fd2);
	printf("\n\nBUFFER -> %d\n\n", BUFFER_SIZE);
	return (0);
}
*/