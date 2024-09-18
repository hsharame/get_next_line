/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:36:43 by hsharame          #+#    #+#             */
/*   Updated: 2024/06/24 16:36:47 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_newline(const char *s, int new)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	if (new)
	{
		while (s[i])
		{
			if (s[i] == '\n')
				return (1);
			i++;
		}
		return (0);
	}
	else
	{
		while (s[i] != '\0')
			i++;
		return (i);
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	*result;

	i = ft_strlen_newline(s1, 0);
	j = ft_strlen_newline(s2, 0);
	result = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!result || !s1 || !s2)
		return (NULL);
	n = i + j;
	i = 0;
	j = 0;
	while (i + j < n)
	{
		while (s1[i] != '\0')
		{
			result[i] = s1[i];
			i++;
		}
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	while (n)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	length;

	length = ft_strlen_newline(s, 0);
	if (start >= length || length == 0)
	{
		result = (char *)malloc(sizeof(char) * 1);
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (len > length - start)
		len = length - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}

char	*ft_getline(char *saved)
{
	char	*line;
	size_t	j;

	j = 0;
	while (saved[j] != '\n' && saved[j] != '\0')
		j++;
	if (saved[j] == '\n')
		j++;
	line = ft_substr(saved, 0, j);
	if (!line)
		return (NULL);
	return (line);
}
