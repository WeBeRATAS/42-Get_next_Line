/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:13:00 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/04/08 16:48:31 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	unsigned long int	i;

	i = 0;
	if (!s)
		return (free(s), NULL);
	while (s[i] != '\0' && s[i] != c)
		i++;
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (!count || !size)
		return (0);
	else
		mem = malloc(count * size);
	if (!mem)
		return (free(mem), NULL);
	while (i < size * count)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	i = 0;
	j = 0;
	if (new == NULL)
		return (free(s1), NULL);
	while (i < len_s1)
	{
		new[i] = s1[i];
		i++;
	}
	while (j < len_s2)
	{
		new[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (new);
}
