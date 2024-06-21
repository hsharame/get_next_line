/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:40:26 by hsharame          #+#    #+#             */
/*   Updated: 2024/06/14 18:59:10 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_newline(const char *saved)
{
	char	*ptr;

	ptr = (char *)saved;
	while (*ptr)
	{
		if (*ptr == '\n')
			return (1);
		ptr++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	*result;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!result || !s1 || !s2)
		return (NULL);
	n = i + j + 1;
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

	length = ft_strlen(s);
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
	result = ft_memcpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}
