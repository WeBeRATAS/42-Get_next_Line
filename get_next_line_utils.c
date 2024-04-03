/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:54:35 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/04/03 14:46:55 by rbuitrag         ###   ########.fr       */
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
/* ft_substr returns a substring of the string str passed as parameter.
  Can be used for line extraction, as it records the end of the previous 
  str and sets its start for the next line of the previous str and sets
  its start for the next line */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sol;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	sol = (char *)malloc(sizeof(char) * (len + 1));
	if (!sol)
	{	
		free(sol);
		return (0);
	}
	i = 0;
	while (i < len && s[start] != '\0')
	{
		sol[i] = s[start];
		i++;
		start++;
	}
	sol[i] = '\0';
	return (sol);
}
/* The ft_strjoin function ensures that enough memory is allocated for the
 *  new buffer, considering both sets of data,  takes the old Basic_buffer
 *   and the read_buffer as arguments and concatenates
 *   them into a new buffer */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*concat;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (ft_strdup(""));
	concat = (char *)malloc(sizeof(char) \
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (concat)
	{
		free(concat);
		return (0);
	}
	i = -1;
	while (s1[++i] != '\0')
		concat[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		concat[i + j] = s2[j];
	concat[i + j] = '\0';
	return (concat);
}
/* The strdup in this case is used to create the divisions of
 * str null or empty */
char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		len;

	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		free(str);
		return (0);
	}
	i = -1;
	while (++i < len)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
/* Function I use to find the line breaks and validate str(*s) or find the
 * end with '\0' */
char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*tmp;

	tmp = (char *)s;
	len = ft_strlen(s);
	if (*(tmp + len) == (char)c)
		return (tmp + len);
	while (len--)
	{
		if (*(tmp + len) == (char)c)
			return (tmp + len);
	}
	return (NULL);
}
