/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:54:07 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/04/03 14:09:14 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int		bytes_read;
	char	*top_buffer;

	top_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (top_buffer == NULL)
	{
		free(top_buffer);
		return (0);
	}
	bytes_read = read(fd, top_buffer, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0 || bytes_read <= 0)
	{
		free(top_buffer);
		return (NULL);
	}
	return (top_buffer);
}

int main(void)
{
 int  fd;
 char *line;
 int  count;

 count = 0;
 fd = open("example01.txt", O_RDONLY);
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
}
