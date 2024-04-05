/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:54:07 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/04/05 12:11:40 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* join and free */
static char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

/* delete line find */
/* find len of first line */
/* if eol == \0 return NULL */
static char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	/*if (!line)
	{
		free(line);
		return (NULL);
	} Si comento esto no cambia nada del paco, asi que sobrara */
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

/* take line for return */
/* if no line return NULL */
/* go to the eol */
static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	/*if (!line)
	{
		free(line);
		return (NULL);
	}No cambia nada si quito esta proteccion en paco*/
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

static char	*ft_read_line(int fd, char *buffer)
{
	char	*tmp;
	int		byte_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	byte_read = 1;
	while (byte_read > 0 && (!ft_strchr(tmp, '\n')))
	{
		byte_read = read(fd, tmp, BUFFER_SIZE);
		if (byte_read == -1 || byte_read > BUFFER_SIZE)
		{
			free(buffer);
			free(tmp);
			return (NULL);
		}
		tmp[byte_read] = '\0';
		buffer = ft_free(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 \
			|| BUFFER_SIZE == 'NULL')
		return (NULL);
	buffer = ft_read_line(fd, buffer);
	if (!buffer)
	{
		//free(buffer); ### No cambia nada en PACO si lo comento
		return (NULL);
	}
	line = ft_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("read_error.txt", O_RDONLY);
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
