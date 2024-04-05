/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:54:35 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/04/05 08:35:16 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* ft_strlen returns a length of the string str passed as parameter. 
 * It can be used to extract buffer length and static string variable. */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* The ft_strjoin function ensures that enough memory is allocated for the
 *  new buffer, considering both sets of data,  takes the old Basic_buffer
 *   and the read_buffer as arguments and concatenates
 *   them into a new buffer */
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	res = ft_calloc(sizeof(char), ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!res)
	{
		free(res);
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = 0;
	return (res);
}

/* Function I use to find the line breaks and validate str(*s) or find the
 * end with '\0'*/
char	*ft_strchr(const char *string, int searChar)
{
	char	*str;

	str = (char *)string;
	while (*str != searChar && *str != 0)
		str++;
	if (*str == searChar)
		return (str);
	else
		return (NULL);
}

/*
void	ft_bzero(char *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}*/

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	result = malloc(count * size);
	if (!result)
			return (0);
	while (i < count * size)
	{
		result[i] = 0;
		i++;
	}
	//ft_bzero(result, (count * size)); # Prueba mas simple PACO igual
	return (result);
}
