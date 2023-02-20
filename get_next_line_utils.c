/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:32:45 by mchiboub          #+#    #+#             */
/*   Updated: 2023/02/17 19:03:17 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr2(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-2);
}

void	ft_strlcpy2(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i <= size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;

	if ((!dest || !src) && !size)
		return (0);
	d = ft_strlen(dest);
	s = ft_strlen(src);
	if (size == 0)
		return (s);
	i = 0;
	while (src[i] && (d + i) < size - 1)
	{
		dest[d + i] = src[i];
		i++;
	}
	if (size < d)
		return (s + size);
	dest[d + i] = '\0';
	return (s + d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s1)
	{
		len2 = ft_strlen(s2);
		str = malloc(len2 + 1);
		if (!str)
			return (NULL);
		ft_strlcpy2(str, s2, len2 + 1);
	}
	else
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = malloc(len1 + len2 + 1);
		if (!str)
			return (NULL);
		ft_strlcpy2(str, s1, len1 + 1);
		ft_strlcat(str, s2, len1 + len2 + 1);
		free(s1);
	}
	return (str);
}

void	ft_substr2(char *str, size_t start)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	while ((start + i) < len)
	{
		str[i] = str[start + i];
		i++;
	}
	str[i] = '\0';
}
