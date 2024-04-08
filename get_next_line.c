/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:12:32 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/04/08 17:06:38 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*leftover;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	leftover = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		leftover[j++] = buffer[i++];
	leftover[j] = '\0';
	free(buffer);
	return (leftover);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (free(line), NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_read_line(int fd, char *buffer)
{
	char	*tmp;
	ssize_t	read_bytes;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (free(buffer), NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), free(tmp), NULL);
		tmp[read_bytes] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	else
		buffer = ft_read_line(fd, buffer);
	if (buffer == NULL)
		return (free(buffer), NULL);
	else
	{
		line = ft_line(buffer);
		buffer = ft_next_line(buffer);
	}
	return (line);
}
/*
int	main(void)
{
	int	fd;

	fd = open("prueba.txt", O_RDONLY);
	if (fd == -1)
	{
		perror ("open");
		exit(EXIT_FAILURE);
	}
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("prueba.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf("[%d]:%s\n", count, line);
		free(line);
		line = NULL;
	}
	close(fd);
		return (0);
}*/
